#include<iostream>

using namespace std;

int call_count = 0;

void PrintArray(int arr[], int l, int r)
{
	int i;
	for(i=l;i<=r;i++)
	{
		cout << arr[i] << " ";
	}
}

void Merge(int arr[], int l, int m, int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int left[n1], right[n2];

	for(i=0;i<n1;i++)
	{
		left[i]=arr[l+i];
	}
	for(i=0;i<n2;i++)
	{
		right[i]=arr[m+1+i];
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int l, int r)
{
	call_count++;
	cout << "Size of Sub problem is : " << r-l+1 << "\n";
	cout << "Array of Sub Problem is : ";
	PrintArray(arr,l,r);
	cout << "\n";
	if(l<r)
	{
		int m;
		m = l + (r-l)/2; //same as (l+r)/2 but avoids overflow
		MergeSort(arr,l,m);
		MergeSort(arr,m+1,r);
		Merge(arr,l,m,r);
	}

}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10}, arr2[]={1, 9, 5, 3, 7, 2, 10, 6, 4, 8};

	cout << "::::For Best Case:::: \n\n";
	MergeSort(arr,0,9);
	cout << "Calls made to MergeSort function in best case : " << call_count << "\n\n";
	call_count = 0;
	cout << "::::For Worst Case:::: \n\n";
	MergeSort(arr2,0,9);
	cout << "Calls made to MergeSort function in worst case : " << call_count << "\n";

}