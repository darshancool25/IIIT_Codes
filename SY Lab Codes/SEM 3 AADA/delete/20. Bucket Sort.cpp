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
void bucketsort(double a[], ll n)
{
	vector<double>v[n];
	for (ll i = 0; i < n; i++)
	{
		ll b = n * a[i];
		v[b].push_back(a[i]);
	}
	for (ll i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	ll index = 0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < v[i].size(); j++)
		{
			a[index++] = v[i][j];
		}
	}
}
int main()
{
	ll n;
	cout << "Enter the size of the Array : ";
	cin >> n;
	double a[n];
	cout << "Enter the elements of the array : " << '\n';
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Array after sorting :" << '\n';
	bucketsort(a, n);
	for (ll i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n';
}
