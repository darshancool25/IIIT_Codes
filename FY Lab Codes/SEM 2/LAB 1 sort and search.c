#include<stdio.h>

int BinarySearch(int arr[],int low, int high, int key)    
{
	int mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		
		if(arr[mid]>key)
		high = mid-1;
		
		else if(arr[mid]<key)
		low = mid+1;
		
		else
		return mid;
    }
    return -1;  
}

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
	int n,temp;
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

	printf("\nEnter the element you want to search in the array : ");
	scanf("%d",&temp);

	temp = BinarySearch(arr,0,n-1,temp);

	if(temp==-1)
	printf("\nThe element was not found");
	
	else
	printf("\nThe element was found in the array");
	
	return 0;
}