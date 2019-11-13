#include<bits/stdc++.h>
#define ll 			long long int
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)

using namespace std;

int main()
{
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