#include<stdio.h>
#include <math.h>

int main()
{
    int low,high,i,dig,sum,num,temp,j;

    printf("Enter lower and upper limit : ");
    scanf("%d %d",&low,&high);

    printf("\nThe Armstrong nos in given range are : ");

    for(i=low;i<=high;i++)
    {
        sum=0;
        dig=0;
        num=i;
        for(;num>0;num=num/10)
        {
            dig++;
        }

        num=i;
        for(;num>0;num=num/10)
        {
            temp=num%10;
            sum += (float)pow(temp,dig);

        }


       if(sum==i)
            printf("%d ",i);

    }
}
