#include<stdio.h>

int main()
{
	int n,key;
	bool flag=false;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	int i,arr[n];
	printf("Enter the array elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);

	}
	printf("Enter the element you wish to search in the array : ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			flag=true;
			break;
		}

	}
	if(flag==true)
	{
		printf("Element found at index : %d",i);
	}
	else
	{
		printf("Entered element was not found");
	}

	return 0;

}
