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
ll getmax(ll a[], ll n)
{
	ll max = a[0];
	for (ll i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}
void countsort(ll a[], ll n, ll pos)
{
	ll output[n];
	ll i, count[10] = {0};
	for (ll i = 0; i < n; i++)
	{
		count[(a[i] / pos) % 10]++;
	}
	for (ll i = 1; i < 10; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	for (ll i = n - 1; i >= 0; i--)
	{
		output[--count[(a[i] / pos) % 10]] = a[i];
	}
	for (ll i = 0; i < n; i++)
	{
		a[i] = output[i];
	}
}
void radixsort(ll a[], ll n)
{
	ll max = getmax(a, n);
	for (ll i = 1; max / i > 0; i = i * 10)
	{
		countsort(a, n, i);
	}
}
int main()
{
	cout << "Enter the size of the array : ";
	ll n;
	cin >> n;
	cout << "Enter the elements of the array : " << '\n';
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Array after radix sort is : " << '\n';
	radixsort(a, n);
	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n';
}
