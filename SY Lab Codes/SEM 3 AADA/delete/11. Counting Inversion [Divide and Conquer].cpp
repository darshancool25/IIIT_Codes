#include<bits/stdc++.h>
#define fo(i,a,b) 		for(i=a;i<b;i++)

using namespace std;

int Merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int left[n1], right[n2];
	int inv_count = 0;   //newly added

	for (i = 0; i < n1; i++)
	{
		left[i] = arr[l + i];
	}
	for (i = 0; i < n2; i++)
	{
		right[i] = arr[m + 1 + i];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
			inv_count += (m + 1) - (l + i); //newly added
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
	return inv_count;  //newly added
}


//modified merge sort function to return inversion count
int MergeSort(int arr[], int l, int r)
{
	int inv_count = 0; //newly added
	if (l < r)
	{
		int m;
		m = l + (r - l) / 2; //same as (l+r)/2 but avoids overflow
		inv_count =  MergeSort(arr, l, m);
		inv_count += MergeSort(arr, m + 1, r);
		inv_count += Merge(arr, l, m, r);
	}

	return inv_count;

}

void Printarray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}



int main()
{
	// boost;
	int n;
	cout << "Enter size of the array : ";
	cin >> n;
	int arr[n];
	cout << "Enter array elements : ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "Number of inversions : " << MergeSort(arr, 0, n - 1) << "\n";
	return 0;

}