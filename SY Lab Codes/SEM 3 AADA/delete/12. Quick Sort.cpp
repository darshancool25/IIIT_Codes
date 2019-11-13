#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void swap(int *a, int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;	
}

int Partition(int arr[], int l, int r)
{
	int temp,pindex,pivot;
	pindex=l;
	//the following {} is for randomizing the pivot
	{
		srand(time(NULL));
		temp = l + ( rand() % ( r - l + 1 ) );
		swap(arr[temp],arr[r]);
	}
	
	pivot=r;
	int i;
	for(i=l;i<r;i++)
	{
		if(arr[i]<=arr[pivot])
		{
			swap(arr[i],arr[pindex]);
			pindex++;
		}
	}
	swap(arr[pindex],arr[r]);
	return pindex;
}


void QuickSort(int arr[], int l, int r)
{
	
	if(l<r)
	{
		int pindex=Partition(arr,l,r);
		
		QuickSort(arr,l,pindex-1);
		QuickSort(arr,pindex+1,r);
		
	}
	
}


int main()
{
	int n,i;
	cout << "Enter size of array : ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements : \n";
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	QuickSort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		cout << arr[i] << ' ';
	}


	return 0;
}