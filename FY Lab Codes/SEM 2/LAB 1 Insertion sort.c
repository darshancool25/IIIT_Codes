#include<stdio.h>

void InsertionSort(int arr[],int n)
{
	int i,j,key;
	
	for(i=1;i<n;i++)
	{
		key = arr[i];
		
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			
			arr[j+1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
}

int main()
{
	int n;
	printf("Enter the size of Array : ");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the elements of the array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	InsertionSort(arr,n);

	printf("The Sorted array is : ");
	for(i=0;i<n;i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;


}