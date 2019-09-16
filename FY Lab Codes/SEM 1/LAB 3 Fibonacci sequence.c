#include <stdio.h>

int main()
{
    int num,temp=0,fib=1;

    printf("Enter a number upto you want FIB sequence : ");
    scanf("%d",&num);

    printf("0 ");

    if(num==1)
    printf("1 1 ");

    for(;fib<num;)
    {
        printf("%d ",fib);
        fib=fib+temp;
        temp = fib-temp;
    }
}
