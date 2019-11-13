#include<bits/stdc++.h>
#define ll 			long long int
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)

using namespace std;
const int N = 10;
ll pre[10000][N];

ll BruteRangeMinima(ll arr[], ll n,ll l, ll r)
{
	ll i,min;
	min = l;
	foe(i,l,r)
	{
		if(arr[i] < arr[min])
			min = i;
	}
	return arr[min];
}

ll HP2(ll n) 
{ 
   ll p = (ll)log2(n); 
   return (ll)pow(2, p);  
}

ll RangeMinima(ll i, ll j)
{
	ll len;
	len = j-i+1;
	if(len == HP2(len))
	{
		ll temp;
		temp = (ll)log2(len);
		return pre[i][temp];
	}
	else
	{
		ll g,h;
		g = HP2(len);
		h = (ll)log2(len);
		return min(pre[i][h], RangeMinima(i+g,j));
	}
}


int main()
{
	
	ll n;
	cout << "Enter the size of the array : ";
	cin >> n;
	ll arr[n+1]; 
	ll i,j,k;
	cout << "Enter the array elements : \n";
	foe(i,1,n)
	{
		cin >> arr[i];
	}
		
	foe(i,1,n)
	{
		bool over = false;
		foe(j,0,N)
		{
			ll min = i;
			foe(k,i,i+pow(2,j)-1)
			{
				if(k>n)
				{
					over = true;
					break;
				}
				if(arr[k] < arr[min])
					min = k;
			}
			pre[i][j] = arr[min];
			if(over)
				break;
		}
	}
	ll q;
	cout << "Enter number of queries : ";
	cin >> q;
	fo(i,0,q)
	{
		ll l,r;
		cout << "\nEnter Query " << i+1 << " :";
		cin >> l >> r;
		cout << "Range Minimum [Brute] : " << BruteRangeMinima(arr,n,l,r);
		cout << "\nRange Minimum [Optimal] : " << RangeMinima(l,r);
	} 
	return 0;
}