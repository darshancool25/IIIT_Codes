#include<stdio.h>

//to get details for 4 salesman each with 3 items... store in 2d array and display details, person total and item total

int main()
{
    int i,j,sale[4][3],pertotal[4]={0},itemtotal[3]={0};

    printf(":::::Sales item Demo:::::\n");
    printf("Enter details for 4 salesman's purchase for 3 items : \n");

    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&sale[i][j]);
            pertotal[i] += sale[i][j];
            itemtotal[j] += sale[i][j];
        }

    }

    printf("\tItem1 \tItem2 \tItem3\n");
    for(i=0;i<4;i++)
    {
        printf("S%d",i+1);
        for(j=0;j<3;j++)
        {
            printf("%9d",sale[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<4;i++)
    {
        printf("Person %d total : %d\n",i+1,pertotal[i]);
    }

    for(j=0;j<3;j++)
    {
        printf("Item %d total : %d\n",j+1,itemtotal[j]);
    }



}
