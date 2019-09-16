#include<stdio.h>

//program to print nth term of fibonacci series using recursion

int Fibo(int n)
{
	if(n<=1)
	return n;
	
	else
	return Fibo(n-1) + Fibo(n-2);
}

int main()
{
	int n;
	printf("Enter number n : ");
	scanf("%d",&n);
	
	printf("The %dth term of Fibonacci series is : %d",n,Fibo(n));
	return 0;
}


