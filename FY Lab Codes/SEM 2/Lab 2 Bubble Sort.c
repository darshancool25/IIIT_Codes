#include<stdio.h>

void BubbleSort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				arr[j]^=arr[j+1];
				arr[j+1]^=arr[j];
				arr[j]^=arr[j+1];
			}
		}
	}
}

int main()
{
	int n;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	BubbleSort(arr,n);
	printf("The sorted array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;

}