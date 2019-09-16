#include <stdio.h>

int main()
{
    int i , j , n1,n2,cnt;

    printf("Enter the lower limit : ");
    scanf("%d",&n1);

    printf("\nEnter the upper limit : ");
    scanf("%d",&n2);

    printf("\nThe prime nos between %d & %d : ",n1,n2);

    for(i=n1;i<=n2;i++)
    {
        cnt=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                cnt++;
        }
        if(cnt==0)
            printf("%d ",i);
    }
}
