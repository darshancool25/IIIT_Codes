#include<stdio.h>

//program to print sum of first n even numbers

int main()
{
	int n,sum;
	printf("Enter a number : ");
	scanf("%d",&n);
	sum = (n*(n+1));
	printf("The sum of first %d even numbers is : %d",n,sum);

	return 0;
}