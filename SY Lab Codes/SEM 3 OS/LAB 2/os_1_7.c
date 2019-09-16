#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
int main() {
int fd,pid;
fd = open("outfile.txt",1);
pid = fork();
if(pid == 0)
{
    write(fd, "hello", 5);
}
close(fd);
return 0;
}
// void func(int signum)
// {
//     wait(NULL);
// }
// int main() {
// int fd,pid;
// fd = open("outfile.txt", O_RDWR);
// pid = fork();
// if(pid == 0){
// write(fd, "hello", 5);
// sleep(100);
// }
// else {
//     // wait(0);
//     // signal(SIGCHLD,func);
//     // write(fd, "parent", 6);
//     exit(0);
// }
// exit(0);
// }