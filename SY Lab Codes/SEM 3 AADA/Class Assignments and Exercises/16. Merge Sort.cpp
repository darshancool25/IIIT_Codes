#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define mk 			make_pair
#define pb 			push_back
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define ll 			long long int
using namespace std;

void Merge(ll arr[], ll l, ll m, ll r)
{
	ll i, j, k;
	ll n1 = m - l + 1;
	ll n2 = r - m;
	ll left[n1], right[n2];

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
}

void MergeSort(ll arr[], ll l, ll r)
{
	if (l < r)
	{
		ll m;
		m = l + (r - l) / 2; //same as (l+r)/2 but avoids overflow
		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);
		Merge(arr, l, m, r);
	}

}

void Printarray(ll arr[], ll n)
{
	ll i;
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}



int main()
{
	// boost;
	ll n, i;
	cout << "Enter the size of Array : ";
	cin >> n;
	ll arr[n];
	cout << "Enter the array elements : ";
	fo(i, 0, n)
	cin >> arr[i];

	MergeSort(arr, 0, n - 1);
	Printarray(arr, n);
	return 0;

}