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
	ll q,n,i,cnt=0, time = 0;
	float sum=0;
	cout << "Enter number of processes : ";
	cin >> n;
	vector <pair<ll,ll>> pro(n+1);
	cout << "Enter pairs of (arrival times and Burst times) of n processes in order : \n";
	foe(i,1,n)
	{
		ll a,b;
		cin >> a >> b;
		pro[i].f = a;
		pro[i].s = b;
		sum -= a;
		sum -= b;
	}

	cout << "Enter time Quanta  : ";
	cin >> q;

	vector <pair < ll, pair <ll,ll> > > wait;  // {process,{arrival time,departure time}}
	wait.pb(mk(-1,mk(-1,-1)));

	ll curr = 1,temp;
	temp = curr;
	ll pivot = -1;
	//Current process in hand is denoted by temp;
	while(cnt<n)
	{
		if((curr == pivot)) //Waiting for next process to arrive
			time++;

		if(time < pro[temp].f) //Process yet to Arrive
		{
			pivot = temp;
			temp = curr;
			continue;
		}
		if(pro[temp].s == 0)
		{
			//process is completed so move to next process
			temp = (temp + 1 > n ? curr : temp + 1);
			continue;
		}

		pivot = -1; // Waiting Time Over!
		
		ll arrtime = time;
		time += pro[temp].s > q ? q : pro[temp].s;  //increasing time accordingly
		pro[temp].s -= pro[temp].s > q ? q : pro[temp].s; //subtracting the utilised time from process accordingly
		wait.pb(mk(temp,mk(arrtime,time)));
		
		if(pro[temp].s == 0)   //Process is completed
		{
			cnt++;
			sum += time;
		}
			

		temp = (temp + 1 > n ? curr : temp + 1);  //move to next process

		if(pro[curr].s == 0) // ++ the starting index of RR
			curr += curr + 1 > n ? 0 : 1;
	}
	fo(i,1,wait.size())
	{
		cout << "P" << wait[i].f << ' ' << "Time : " << wait[i].s.f << " to " << wait[i].s.s << '\n';
	}
	cout << "Average Waiting time : " << (float)(sum/n);

	return 0;

}