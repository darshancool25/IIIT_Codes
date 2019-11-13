#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int BinarySearch(ll arr[],ll low, ll high, ll key)    //the array passed should be a sorted array
{
	ll mid;
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
    return -1;   // key not found
}
int main()
{
	ll n,i;
	cout<<"Enter the Size of the array : ";
	cin>>n;
	
	ll arr[n];
	cout<<"\nEnter the elements of the array in ascending order : ";
	
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	ll temp;
	
	cout<<"\nEnter the element you want to search in the array : ";
	cin>>temp;
	
	temp = BinarySearch(arr,0,n-1,temp);
	
	if(temp==-1)
	cout<<"\nThe element was not found";
	
	else
	cout<<"\nThe element was found at index "<<temp;
	
	return 0;
	
	
}
