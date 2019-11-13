#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll 			long long int
#define mk 			make_pair
#define pb 			push_back
#define f			first
#define s			second
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)
#define MOD			1000000007

using namespace std;

int main()
{
	// boost;
	ll n;
	cout << "Enter size of array : ";
	cin >> n;
	ll arr[n];
	ll i;
	cout << "Enter array elements : ";
	fo(i,0,n)
		cin >> arr[i];
	cout << "Max Sum of Subarray is : ";
	ll sum[n];
	sum[0] = arr[0];
	fo(i,1,n)
	{	
		if(sum[i-1] < 0)
			sum[i] = arr[i];
		else
			sum[i] = sum[i-1] + arr[i];
	}
	sort(sum,sum+n);
	cout << sum[n-1];
	return 0;
}