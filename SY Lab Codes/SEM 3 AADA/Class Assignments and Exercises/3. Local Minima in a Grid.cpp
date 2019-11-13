//Procedure : Column-Column ;  O(n.logn) 
//Kindly complete Procedure Row-Column Solution ; O(c.n)
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
const long long int N = 1000;
ll arr[N][N];

//returns minimum in a column For Procedure Column Column
ll FindMin(ll n,ll c)
{
	ll i,min_ind = 0;
	fo(i,0,n)
	{
		if(arr[i][c] < arr[min_ind][c])
			min_ind = i;
	}
	return min_ind;
}

//Finds Local Minima in grid (row r1 to r2 & column c1 to c2)
//Procedure Column-Column
ll Check(ll n,ll r,ll c)
{
	ll right,left,ele;
	ele = arr[r][c];
	right = arr[r][(c+1 >= n ? c : c+1)];
	left = arr[r][(c-1 < 0 ? c : c-1)];
	if(right < ele)
		return 1;
	else if(left < ele)
		return -1; 
	else
		return 0;
}

ll LocalMinimaCC(ll n,ll low, ll high)
{
	ll min,mid,check;
	ll cnt = 1;
	while(low <= high)
	{
		// cout << "Pass : " << cnt;
		mid = (low+high)/2;
		min = FindMin(n,mid);
		check = Check(n,min,mid);
		// cout << " Min : " << arr[min][mid] << " Check : " << check << '\n'; 
		if(check == 0)
			return arr[min][mid];
		else if(check == 1)
			low = mid + 1;
		else
			high = mid - 1;
		cnt++;
	}
}


//Procedure Row-Column
ll LocalMinimaRC(ll n,ll r1, ll r2, ll c1, ll c2)
{

}



int main()
{
	// boost;
	ll i,j,n;
	cout << "Enter dimension [n] of (n*n) Grid : ";
	cin >> n;
	cout << "Enter Grid Elements : \n";
	fo(i,0,n)
	{
		fo(j,0,n)
		{
			cin >> arr[i][j];
		}
	}

	cout << "\nLocal Minima in Grid is : " << LocalMinimaCC(n,0,n-1);
	return 0;
}