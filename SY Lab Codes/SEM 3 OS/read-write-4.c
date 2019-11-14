/* A readers/writers program for multiple readers and multiple writers  */
#include <sys/types.h>     /* for pid_t */
#include <unistd.h>        /* for fork */   
#include <stdio.h>         /* for printf */
#include <sys/mman.h>      /* for mmap */
#include <sys/wait.h>      /* for waitpid */
#include <stdlib.h>        /* for exit */
#include <sys/sem.h>       /* for semaphore processing */

#define NUM_READERS 5  /* number of reader processes to be spawned */
#define NUM_WRITERS 6  /* number of writer processes to be spawned */

#define BUF_SIZE 5            /* logical size of buffer */
#define SHARED_MEM_SIZE (BUF_SIZE+2)*sizeof(int) /* size of shared memory */
#define reader_length 12  /* number of iterations for reader in test run */
#define writer_length 10  /* number of iterations for writer in test run */

#define buf_used 0     /* semaphore array index to check buffer elts used */
#define buf_space 1    /* semaphore array index to check buffer elts empty */
#define mutex 2        /* semaphore index for mutual exclusion to buffer*/

int sem_create(int num_semaphores)
{  /* procedure to create specified number of semaphores */
   int semid;

   /* create new semaphore set of semaphores */
   if ((semid = semget (IPC_PRIVATE, num_semaphores, IPC_CREAT | 0600)) < 0)
     {  perror ("error in creating semaphore");/* 0600 = read/alter by user */
        exit (1);
     }
   return semid;
}

void sem_init(int semid, int index, int value)
{  /* procedure to initialize specified semaphore to given value */
   if (semctl (semid, index, SETVAL, value) < 0)
     {  perror ("error in initializing first semaphore");
        exit (1);
     }
}

void P(int semid, int index)
{/* procedure to perform a P or wait operation on a semaphore of given index */
  struct sembuf sops[1];  /* only one semaphore operation to be executed */
   
   sops[0].sem_num = index;/* define operation on semaphore with given index */
   sops[0].sem_op  = -1;   /* subtract 1 to value for P operation */
   sops[0].sem_flg = 0;    /* type "man semop" in shell window for details */

   if (semop (semid, sops, 1) == -1)
     {  perror ("error in semaphore operation");
        exit (1);
     }
}

void V(int semid, int index)
{/* procedure to perform a V or signal operation on semaphore of given index */
   struct sembuf sops[1];  /* define operation on semaphore with given index */

   sops[0].sem_num = index;/* define operation on semaphore with given index */
   sops[0].sem_op  = 1;    /* add 1 to value for V operation */
   sops[0].sem_flg = 0;    /* type "man semop" in shell window for details */

   if (semop (semid, sops, 1) == -1)
     {  perror ("error in semaphore operation");
        exit (1);
     }
}

int main (void)
{  pid_t pid;          /* variable to record process id of child */

   /* shared memory elements */
   caddr_t shared_memory;   /* shared memory base address */
   int *in;         /* pointer to logical 'in' address for writer */
   int *out;        /* pointer to logical 'out' address for reader */
   int *buffer;     /* logical base address for buffer */

   /* semaphore elements */
   int semid;       /* identifier for a semaphore set */

   /* record of spawned processes */
   pid_t proc[NUM_READERS+NUM_WRITERS];

   /* local variables */
   int p_count, i;  /* index variables */
   int value;       /* value read by child */

   /* set up shared memory segment */
   shared_memory=mmap(0, SHARED_MEM_SIZE, PROT_READ | PROT_WRITE, 
                              MAP_ANONYMOUS | MAP_SHARED, -1, 0);
   if (shared_memory == (caddr_t) -1)
     { perror ("error in mmap while allocating shared memory\n");
       exit (1);
     }

   /* set up pointers to appropriate places in shared memory segment */
   buffer = (int*) shared_memory; /* logical buffer starts at shared segment */
   in  = (int*) shared_memory + BUF_SIZE*sizeof(int);
   out = (int*) shared_memory + (BUF_SIZE+1)*sizeof(int);

   *in = *out = 0;          /* initial starting points */

   /* create and initialize semaphores */
   semid = sem_create(3);
   sem_init(semid, buf_used, 0);
   sem_init(semid, buf_space, BUF_SIZE);
   sem_init(semid, mutex, 1);

   /* spawn writer processes */
   for (p_count = 1; p_count <= NUM_WRITERS; p_count++)
     { if (-1 == (pid = fork())) /* spawn child process */
        { perror ("error in fork");  
          exit (1);
        }

       if (0 == pid)             
        { /* processing for parent == writer */
          printf ("The writer process %d begins.\n", p_count);
       
          for (i = 0; i < writer_length; i++)
            {value = 100*p_count + i;/* writer == first digit of value */
             P(semid, buf_space);/* wait semaphore for space available */
             P(semid, mutex);    /* wait semaphore for buffer access */
             buffer[*in] = value;/* put data in buffer */
             *in = (*in + 1) % BUF_SIZE;
             V(semid, mutex);    /* signal semaphore for buffer access */
             V(semid, buf_used); /* signal semaphore for something used */
             /*printf ("Writer %d: item %2d put %d in buffer\n", j_child);*/
            }
          printf ("Writer %d done.\n", p_count);  
          exit(0);
        }
       else proc[p_count-1] = pid;
     }

   /* spawn reader processes */
   for (p_count = 1; p_count <= NUM_READERS; p_count++)
     { if (-1 == (pid = fork())) /* spawn child process */
        { perror ("error in fork");  
          exit (1);
        }

       if (0 == pid)             
         { /* processing for child == reader */
           printf ("The reader process %d begins.\n", p_count);

           for (i = 0; i < reader_length; i++)
             {P(semid, buf_used);  /* wait semaphore for something used */
              P(semid, mutex);     /* wait semaphore for buffer access */
              value = buffer[*out];/* take data from buffer */
              *out = (*out + 1) % BUF_SIZE;
              V(semid, mutex);     /* signal semaphore for buffer access */
              V(semid, buf_space); /* signal semaphore for space available */
              printf ("Reader %d: item %2d == %2d\n", p_count, i, value);
              if ((i+p_count)%5 == 0) /* pause somewhere in processing */
                sleep(1);             /* to make output more interesting */
             }
           printf ("Reader %d done.\n", p_count);
           exit(0);
         }
       else proc[p_count+NUM_READERS-1] = pid;
     }

   /* wait for all children to finish */
   printf("All child processes spawned by parent\n");
   printf("Parent waiting for children to finish\n");

   for (p_count = 0; p_count<NUM_WRITERS+NUM_READERS; p_count++)
     waitpid(proc[p_count], NULL, 0);

   /* deallocate shared memory */
   munmap (shared_memory, SHARED_MEM_SIZE);

   /* Remove the semaphore from the system and destroy the set of 
      semaphores and data structure associated with it. */  
   if (semctl (semid, 0, IPC_RMID) < 0)   
     {  perror ("error in removing semaphore from the system"); 
        exit (1); 
     }
   printf ("Semaphore cleanup complete.\n");
   
   exit (0);
}
