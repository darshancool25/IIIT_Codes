#include<stdio.h>

int main()
{
    int i,n1,n2,gcd=1,lcm;

    printf("Enter 2 numbers : ");

    scanf("%d %d",&n1,&n2);

    if(n1<n2)
    {
        for(i=n1;i>=1;i--)
        {
            if(n1%i==0 && n2%i==0)
             {
                 gcd=i;
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
                 gcd=i;
                 break;
              }
        }
    }

    else
    {
        gcd=n1;
    }

    lcm = (n1*n2)/gcd;
    printf("\nThe LCM of given two numbers is %d",lcm);



    return 0;
}
