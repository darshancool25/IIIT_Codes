/* A readers/writers program using a shared buffer and semaphores  */
#include <sys/types.h>     /* for pid_t */
#include <unistd.h>        /* for fork */   
#include <stdio.h>         /* for printf */
#include <sys/mman.h>      /* for mmap */
#include <sys/wait.h>      /* for waitpid */
#include <stdlib.h>        /* for exit */
#include <sys/sem.h>       /* for semaphore processing */

#define BUF_SIZE 5            /* logical size of buffer */
#define SHARED_MEM_SIZE (BUF_SIZE+2)*sizeof(int) /* size of shared memory */
#define run_length 10  /* number of iterations in test run */

#define buf_used 0     /* semaphore array index to check buffer elts used */
#define buf_space 1    /* semaphore array index to check buffer elts empty */

int sem_init(void)
{  /* procedure to create and initialize semaphores and return semaphore id,
      assuming two semaphores defined in the given array of semaphores     */
   int semid;

   /* create new semaphore set of 2 semaphores */
   if ((semid = semget (IPC_PRIVATE, 2, IPC_CREAT | 0600)) < 0)
     {  perror ("error in creating semaphore");/* 0600 = read/alter by user */
        exit (1);
     }

   /* initialization of semaphores */
   /* BUF_SIZE free spaces in empty buffer */
   if (semctl (semid, buf_space, SETVAL, BUF_SIZE) < 0)
     {  perror ("error in initializing first semaphore");
        exit (1);
     }

   /* 0 items in empty buffer */
   if (semctl (semid, buf_used, SETVAL, 0) < 0) 
     {  perror ("error in initializing second semaphore");
        exit (1);
     }
   return semid;
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

   /* local variables */
   int i_child, j_child;   /* index variables */
   int value;              /* value read by child */

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

   /* create and initialize semaphore */
   semid = sem_init();

   if (-1 == (pid = fork())) /* check for error in spawning child process */
     { perror ("error in fork");  
       exit (1);
     }

   if (0 == pid)             
     { /* processing for child == reader */
       printf ("The reader process begins.\n");

       for (i_child = 0; i_child < run_length; i_child++)
         {  P(semid, buf_used);  /* wait semaphore for something used */
            value = buffer[*out];
            *out = (*out + 1) % BUF_SIZE;
            printf ("Reader's report: item %2d == %2d\n", i_child, value);
            V(semid, buf_space); /* signal semaphore for space available */
            if ((i_child % 3) == 1)
              sleep(1);  /* take time to process every third element */
         }
       printf ("Reader done.\n");
     } 
  else 
     { /* processing for parent == writer */
       printf ("The writer process begins.\n");
       
       for (j_child = 0; j_child < run_length; j_child++)
         {  P(semid, buf_space);/* wait semaphore for space available */
            buffer[*in] = j_child*j_child;    /* put data in buffer */
            *in = (*in + 1) % BUF_SIZE;
            printf ("Writer's report: item %2d put in buffer\n", j_child);
            V(semid, buf_used); /* signal semaphore for something used */
            if ((j_child % 4) == 0)
              sleep(1); /* take time to generate every fourth element */
          }
       waitpid(pid, NULL, 0);
       printf ("Writer done.\n");  

       /* deallocate shared memory */
       munmap (shared_memory, SHARED_MEM_SIZE);

       /* Remove the semaphore from the system and destroy the set of
          semaphores and data structure associated with it. */
       if (semctl (semid, 0, IPC_RMID) < 0)
         {  perror ("error in removing semaphore from the system");
            exit (1);
         }
       printf ("Semaphore cleanup complete.\n");
     }
   exit (0);
}
