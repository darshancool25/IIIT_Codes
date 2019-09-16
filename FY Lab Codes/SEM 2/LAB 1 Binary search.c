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

int main()
{
	int n,temp;
	printf("Enter the size of Array : ");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the elements of the array(in sorted manner) : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nEnter the element you want to search in the array : ");
	scanf("%d",&temp);

	temp = BinarySearch(arr,0,n-1,temp);

	if(temp==-1)
	printf("\nThe element was not found");
	
	else
	printf("\nThe element was found at index : %d", temp);
	
	return 0;



}