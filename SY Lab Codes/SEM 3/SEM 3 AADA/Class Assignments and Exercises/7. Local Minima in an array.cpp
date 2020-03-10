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
ll Check(ll arr[],ll n,ll c)
{
	ll right,left,ele;
	ele = arr[c];
	right = arr[(c+1 >= n ? c : c+1)];
	left = arr[(c-1 < 0 ? c : c-1)];
	if(right < ele)
		return 1;
	else if(left < ele)
		return -1; 
	else
		return 0;
}

ll LocalMinima(ll arr[],ll n,ll low, ll high)
{
	ll check,mid;
	while(low <= high)
	{
		mid = low + (high-low)/2;
		check = Check(arr,n,mid);
		if(check == 0)
			return arr[mid];
		else if(check == 1)
			low = mid + 1;
		else
			high = mid - 1;
	}

}

int main()
{
	// boost;
	ll n;
	cout << "Enter size of array : ";
	cin >> n;
	ll arr[n],i;
	cout << "Enter elements of array : ";
	fo(i,0,n)
	{
		cin >> arr[i];
	}
	cout << "Local Minima in Array : " << LocalMinima(arr,n,0,n-1);
	return 0;
}