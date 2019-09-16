#include<stdio.h>
//program to print sum of first n natural numbers
int RecSum(int n)
{
	if(n==1)
		return 1;
	else
		return n+RecSum(n-1);
}

int main()
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("The sum of first %d natural numbers is : %d",n,RecSum(n));

	return 0;
}