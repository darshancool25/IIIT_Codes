#include<stdio.h>

int main()
{
    int i,n,cnt1=0,cnt2=0,cnt3=0;

    printf("Enter the number of students : ");
    scanf("%d",&n);

    int arr[n];

    printf("\nEnter the marks : ");

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

        if(arr[i]>80 && arr[i]<=100)
            cnt3++;

        if(arr[i]>60 && arr[i]<=80)
            cnt2++;

        if(arr[i]>40 && arr[i]<=60)
            cnt1++;
    }

    printf("\nNo. of students in range 40-60 : %d",cnt1);
    printf("\nNo. of students in range 60-80 : %d",cnt2);
    printf("\nNo. of students in range 80-100 : %d",cnt3);
}
