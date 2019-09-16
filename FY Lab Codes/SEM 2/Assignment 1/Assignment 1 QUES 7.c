#include<stdio.h>
//program to print n factorial using recursion

int Factorial(int n)
{
	if(n==1)
		return 1;

	else
		return n*Factorial(n-1);
}

int main()
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("The Value of %d! is : %d",n,Factorial(n));
	return 0;

}