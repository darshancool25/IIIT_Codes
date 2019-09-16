#include<stdio.h>

//program to print gcd of two numbers using recursion

int gcd(int a, int b)
{
	if(b==0)
	return a;
	
	else
	return gcd(b,a%b);
}

int main()
{
	int m,n;
	
	printf("Enter two numbers (a>b) : " );
	scanf("%d %d",&m,&n);
	
	printf("The GCD of %d & %d is : %d",m,n,gcd(m,n));
}


