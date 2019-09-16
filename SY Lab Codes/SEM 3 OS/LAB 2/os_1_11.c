#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   execl("/bin/cp", "cp", argv[1], argv[2],(char *)0);
   return 0;
}