#include<stdio.h>

int main()
{
    int n,i,sum=0,avg;
    printf("Enter number of elements : ");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter the elements : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    avg = sum/n;
    printf("\nThe sum of all elements : %d",sum);
    printf("\nThe average of the elements : %d",avg);

    return 0;
}
