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
	ll i,burst[n],wait[n];
	cout << "Enter burst times of n processes in order : ";
	fo(i,0,n)
		cin >> burst[i]; 

	sort(burst,burst+n);
	wait[0] = 0;
	float sum=0;
	fo(i,1,n)
	{
		wait[i] = wait[i-1] + burst[i-1];
		sum += wait[i];
	}
	cout << "Waiting time for processes : ";
	fo(i,0,n)
		cout << wait[i] << ' ';
	
	cout << "\nAverage waiting time : " << (float)(sum/n);
	return 0;

}