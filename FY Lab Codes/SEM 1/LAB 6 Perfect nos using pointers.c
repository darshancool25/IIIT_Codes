#include<stdio.h>

int main()
{
	int num, flag=0;
	
	printf("Enter a number : ");
	scanf("%d",&num);
	
	Perfect(&num,&flag);
	
	if(flag==1)
	printf("\nThe entered number is a perfect number");
	
	
	else
	printf("\nThe entered number is not a perfect number");
	
	return 0;
	
}

void Perfect(int *num, int *flag)
{
	int i,sum=0;
	for(i=1;i<*num;i++)
	{
		if(*num%i==0)
		{
			sum += i;
		}
	}
	if(sum==*num)
	*flag=1;
	
	else 
	*flag=0;
}
