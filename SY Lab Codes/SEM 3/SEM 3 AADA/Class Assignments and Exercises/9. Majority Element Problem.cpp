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
	ll n, i, cnt = 1;
	cout << "Enter size of array : ";
	cin >> n;
	char arr[n];
	cout << "Enter n characters : ";
	fo(i, 0, n)
	cin >> arr[i];
	char ind = 0;
	fo(i, 1, n)
	{
		if (arr[i] == arr[ind])
			cnt++;
		else
			cnt--;
		if (cnt == 0)
		{
			ind = i;
			cnt = 1;
		}
	}
	cnt = 0;
	fo(i, 0, n)
	{
		if (arr[i] == arr[ind])
			cnt++;
	}
	if (cnt > n / 2)
		cout << "Majority element is : '" << arr[ind] << '\'';
	else
		cout << "No majority element in the array!";
}