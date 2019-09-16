#include<stdio.h>

int main()
{
    int a,b,c,max;

    printf("Enter three numbers : ");
    scanf("%d %d %d",&a,&b,&c);

    Maximum(&a,&b,&c,&max);

    printf("\nThe maximum amongst three numbers is : %d",max);

    return 0;

}

void Maximum(int *a, int *b,int *c, int *max)
{
    if(*a>=*b && *a>=*c)
        *max=*a;

    else if(*b>=*a && *b>=*c)
        *max=*b;

    else
        *max=*c;
}
