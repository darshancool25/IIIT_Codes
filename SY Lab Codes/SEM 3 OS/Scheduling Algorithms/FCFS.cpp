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
	cout << "Enter number of processes : ";
	cin >> n;
	ll i,arr[n+1],burst[n+1],wait[n+1];
	cout << "Enter burst times of n processes in order : ";
	foe(i,1,n)
		cin >> burst[i]; 
	
	cout << "Enter order of processes : ";
	foe(i,1,n)
		cin >> arr[i];
		
	wait[1] = 0;
	float sum = 0;
	foe(i,1,n-1)
	{
		wait[i+1] = wait[i] + burst[arr[i]];
		sum += wait[i+1];
	}
	cout << "Waiting time for processes : ";
	foe(i,1,n)
		cout << wait[i] << ' ';

	cout << "\nAverage waiting time : " << (float)(sum/n);
}