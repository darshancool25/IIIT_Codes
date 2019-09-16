#include<stdio.h>

int main()
{
    int n,i,temp,pos;

    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int arr[n+1];

    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\nEnter the position to insert an extra element : ");
    scanf("%d",&pos);

    printf("\nEnter the element : ");
    scanf("%d",&temp);

    for(i=n;i>=pos;i--)
        arr[i]=arr[i-1];

    arr[pos] = temp;

    for(i=0;i<n+1;i++)
        printf("%d ",arr[i]);
}
