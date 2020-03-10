#include<bits/stdc++.h>
#define ll long long int

using namespace std;

void InsertionSort(ll arr[],ll n)
{
	ll i,j,key;
	//main iterator loop
	for(i=1;i<n;i++)
	{
		key = arr[i];
		//insert arr[i] into the sorted sequence arr[0......i-1]
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			//swap arr[j] and arr[j+1]
			arr[j+1] = arr[j];
			arr[j] = key;
			j--;
		}
		
	}
}

int main()
{
	ll n,i;
	cout<<"Enter the number of elements : ";
	cin>>n;
	
	ll a[n];
	cout<<"\nEnter the Elements : ";
	for(i=0;i<n;i++)
	cin>>a[i];
	
	InsertionSort(a,n);
	
	cout<<"\nThe Sorted array is :";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	
	return 0;
}