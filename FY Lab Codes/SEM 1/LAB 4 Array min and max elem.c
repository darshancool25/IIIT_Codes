#include<stdio.h>

int main()
{
    int i,n,min=0,max=0;

    printf("Enter the number of elements :" );
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter the array elements : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        if(arr[i]>arr[max])
            max = i;

        if(arr[i]<arr[min])
            min = i;
    }

    printf("\nThe smallest element is : %d",arr[min]);
    printf("\nThe largest element is : %d",arr[max]);

    return 0;


}
