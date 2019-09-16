#include<stdio.h>

int main()
{
    int i,n1,n2;

    printf("Enter 2 numbers : ");

    scanf("%d %d",&n1,&n2);

    printf("\nThe GCD of entered 2 nos is : ");

    if(n1<n2)
    {
        for(i=n1;i>=1;i--)
        {
            if(n1%i==0 && n2%i==0)
             {
                 printf("%d",i);
                 break;

             }
        }
    }

    else if(n1>n2)
    {
        for(i=n2;i>=1;i--)
        {
            if(n1%i==0 && n2%i==0)
              {
                 printf("%d",i);
                 break;

              }
        }
    }

    else
        printf("%d",n1);

    return 0;
}
