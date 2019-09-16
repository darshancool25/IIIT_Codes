#include<stdio.h>

//program to print sum of first n odd numbers

int main()
{
	int n,sum;
	printf("Enter a number : ");
	scanf("%d",&n);
	sum = (n*n);
	printf("The sum of first %d odd numbers is : %d",n,sum);

	return 0;
}