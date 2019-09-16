#include<stdio.h>

//program to print sum of cubes of first n natural numbers

int main()
{
	int n,sum;
	printf("Enter a number : ");
	scanf("%d",&n);
	sum = (n*(n+1))/2;
	sum*=sum;
	printf("The sum of cubes of first %d natural numbers is : %d",n,sum);

	return 0;
}