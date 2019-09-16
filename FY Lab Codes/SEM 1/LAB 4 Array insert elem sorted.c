#include<stdio.h>

int main()
{
    int i,n,temp,pos;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int arr[n+1];

    printf("\nEnter the array elements in ascending order : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element you want to insert : ");
    scanf("%d",&temp);

    pos=n;


    for(i=0;i<n;i++)
    {
        if(arr[i]>temp)
        {
            pos=i;
            break;
        }
    }

    for(i=n;i>=pos;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = temp;

    printf("\nThe new sorted array with inserted element : ");
    for(i=0;i<n+1;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;

}
