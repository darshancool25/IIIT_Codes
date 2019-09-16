#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int i,sum=0;
	
	for(i=1;i<argc;i++)
	{
		sum += atoi(argv[i]);	
	}
	printf("Sum of all arguments is : %d",sum);
	return 0;
}
