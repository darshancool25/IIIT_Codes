#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int a,b,sum;
	
	if(argc!=3)
	{
		printf("PLease use \"prg_name value1 value 2\"\n");
		return -1;
	}
	a=atoi(argv[1]);
	b=atoi(argv[2]);
	sum=a+b;
	
	printf("Sum of %d & %d is : %d",a,b,sum);
	
	return 0;
	
}
