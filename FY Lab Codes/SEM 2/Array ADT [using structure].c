#include<stdio.h>
#include<stdlib.h>

struct ArrayAdt
{
	int capacity,lastindex,*ptr;
};

struct ArrayAdt * Create(int capacity)
{
	struct ArrayAdt *arr;
	arr = (struct ArrayAdt*)malloc(sizeof(struct ArrayAdt));
	arr->capacity = capacity;
	arr->lastindex=-1;
	arr->ptr = (int*)malloc(arr->capacity*sizeof(int));

	return arr;
}

int GetItem(struct ArrayAdt *arr,int index)
{
	if(index>arr->lastindex||index<0)
	{
		printf("\nInvalid Index!");
		return(-1);
	}
	else
		return arr->ptr[index];
}

int SetItem(struct ArrayAdt *arr,int index,int data)
{
	if(index<0||index>arr->lastindex+1||index>=arr->capacity)
	{
		printf("Cant set!");
		return (-1);
	}

	else if(index==arr->lastindex+1)
	{
		arr->ptr[arr->lastindex+1]=data;
		arr->lastindex++;
		return 1;
	}

	else if(index>=0 && index<=arr->lastindex)
	{
		int i;
		for(i=arr->lastindex+1;i!=index;i--)
		{
			arr->ptr[i]=arr->ptr[i-1];
		}
		arr->ptr[index]=data;
		arr->lastindex++;
		return 1;
	}
	else
		return (-1);
}


int EditItem(struct ArrayAdt *arr,int index,int data)
{
	if(index>=0 && index<=arr->lastindex)
	{
		arr->ptr[index]=data;
		return 1;
	}
	else
	{
		printf("Invalid Operation!");
		return (-1);
	}
}

int CountItem(struct ArrayAdt *arr)
{
	return (arr->lastindex)+1;
}

int RemoveItem(struct ArrayAdt *arr,int index)
{
	if(index==arr->lastindex)
	{
		arr->lastindex--;
		return 1;
	}

	else if(index>=0 && index<arr->lastindex)
	{
		int i;
		for(i=index;i<arr->lastindex;i++)
		{
			arr->ptr[i]=arr->ptr[i+1];
		}
		arr->lastindex--;
		return 1;
	}

	else
	{
		printf("Invalid Operation!");
		return -1;
	}
}

int Search(struct ArrayAdt *arr,int key)
{
	if(arr->lastindex==-1)
	{
		printf("Invalid Operation!");
		return -1;
	}

	int i;
	for(i=0;i<=arr->lastindex;i++)
	{
		if(arr->ptr[i]==key)
		{
			return i;
		}
	}

	return -1;

}

int Sort(struct ArrayAdt *arr)
{
	if(arr->lastindex==-1)
	{
		printf("Array is empty!");
		return -1;
	}
	int n,i,j;
	n = arr->lastindex+1;
	printf("\nno ele - %d",n);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr->ptr[j]>arr->ptr[j+1])
			{
				
				arr->ptr[j] ^= arr->ptr[j+1];
				arr->ptr[j+1] ^= arr->ptr[j];
				arr->ptr[j] ^= arr->ptr[j+1];
			}
		}
	}
	return 1;
}

void Print(struct ArrayAdt *arr)
{	
	if(arr->lastindex>-1)
	{
		int i;
		for(i=0;i<=arr->lastindex;i++)
		{
			printf("%d ",arr->ptr[i]);

		}
		printf("\nLast Index = %d",arr->lastindex);
	}
	else
	{
		printf("\nInvalid!");
	}
}

int main()
{
	int ch=1,temp,data;

	while(ch!=9)
	{
		printf("\n0. Print Array");
		printf("\n1. Create Array");
		printf("\n2. Get Item");
		printf("\n3. Set Item");
		printf("\n4. Edit Item");
		printf("\n5. Count Item");
		printf("\n6. Remove Item");
		printf("\n7. Search");
		printf("\n8. Sort");
		printf("\n9. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{

			case 1:
			struct ArrayAdt *arr;
			printf("\nEnter Capacity of the Array : ");
			scanf("%d",&temp);
			arr = Create(temp);
			break;

			case 0:
			Print(arr);
			break;

			case 2:
			printf("\nEnter index : ");
			scanf("%d",&temp);
			temp = GetItem(arr,temp);
			if(temp!=-1)
			{
				printf("Element is : %d",temp);
			}
			break;

			case 3:
			printf("\nEnter index : ");
			scanf("%d",&temp);
			printf("\nEnter data : ");
			scanf("%d",&data);
			SetItem(arr,temp,data);
			break;

			case 4:
			printf("\nEnter index : ");
			scanf("%d",&temp);
			printf("\nEnter data : ");
			scanf("%d",&data);
			EditItem(arr,temp,data);
			break;

			case 5:
			printf("\nNo. of items : %d",CountItem(arr));
			break;

			case 6:
			printf("\nEnter index : ");
			scanf("%d",&temp);
			if(RemoveItem(arr,temp))
				printf("\nItem Removed Successfully!");
			break;

			case 7:
			printf("\nEnter item to be searched : ");
			scanf("%d",&data);
			temp = Search(arr,data);
			if(temp>-1)
			{
				printf("\nElement found at index : %d",temp);
			}
			else
			{
				printf("\nElement not found!");
			}
			break;

			case 8:
			Sort(arr);
			printf("\nArray Sorted!");
			break;

			case 9:
			return 0;
		}
	}

	return 0;
}