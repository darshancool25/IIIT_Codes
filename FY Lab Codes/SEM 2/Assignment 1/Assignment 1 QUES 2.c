#include<stdio.h>
//program to print sum of square of first n natural numbers
int RecSquareSum(int n)
{
	if(n==1)
		return 1;
	else
		return (n*n)+RecSquareSum(n-1);
}

int main()
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("The sum of squares of first %d natural numbers is : %d",n,RecSquareSum(n));

	return 0;
}