#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *arr, i,n,max;
	
	printf("How many elements do you wish to enter : ");
	scanf("%d",&n);
	
	arr = (int *)malloc(n*sizeof(int));
	
	printf("\nEnter the elements : ");
	scanf("%d",arr);
	max=*arr;
	
	for(i=1;i<n;i++)
	{
		scanf("%d",arr+i);
		if(*(arr+i)>max)
		max=*(arr+i);
	}
	
	printf("\nThe maximum element is : %d",max);
	
	return 0;
	
}
