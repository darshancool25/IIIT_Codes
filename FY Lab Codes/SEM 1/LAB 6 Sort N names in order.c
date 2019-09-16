#include<stdio.h>
#include<string.h>

int main()
{
    char arr[10][20],temp[20];
    int i,j,n;

    n=10;

    printf("Enter 10 names : ");
    for(i=0;i<10;i++)
    {
        scanf("%s",arr[i]);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(arr[i],arr[j])>0)
            {
                strcpy(temp,arr[i]);
                strcpy(arr[i],arr[j]);
                strcpy(arr[j],temp);
            }
        }
    }

    for(i=0;i<10;i++)
    {
        printf("%s\n",arr[i]);
    }

    return 0;


}




