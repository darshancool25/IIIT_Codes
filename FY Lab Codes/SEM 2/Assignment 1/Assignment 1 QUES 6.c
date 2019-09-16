#include<stdio.h>

//program to print binary representation of a decimal number

int Binary(int n) 
{ 
    if (n == 0)  
        return 0;  
    else
        return (n % 2 + 10 * Binary(n / 2)); 
}

int main()
{
	int n;
	printf("Enter a number : ");
	scanf("%d",&n);
	printf("The Binary representation of %d is : %d",n,Binary(n));
	
	return 0;
}