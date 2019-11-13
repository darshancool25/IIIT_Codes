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
void heapify(ll a[], ll n, ll i)
{
	ll lt = i;
	ll lc = 2 * i + 1;
	ll rc = 2 * i + 2;
	if (lc < n && a[lc] > a[lt])
	{
		lt = lc;
	}
	if (rc < n && a[rc] > a[lt])
	{
		lt = rc;
	}
	if (lt != i)
	{
		swap(a[i], a[lt]);
		heapify(a, n, lt);
	}
}
void heapsort(ll a[], ll n)
{
	for (ll i = n / 2 - 1; i >= 0; i--)
	{
		heapify(a, n, i);
	}
	for (ll i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}
int main()
{
	ll n;
	cout << "Enter the size of the array : ";
	cin >> n;
	ll a[n];
	cout << "Enter the elements of the array : " << '\n';
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Array after sorting :" << '\n';
	heapsort(a, n);
	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n';
}
