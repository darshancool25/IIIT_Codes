//This is Non-Graph Solution to the problem
//Complete the Graph solution to this problem by adding edges and then applying BFS/DFS.
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
	ll m,i,n,u;
	
	cout << "Enter Dimensions of grid : ";
	cin >> m >> n;
	
	bool arr[(m*n)];
	fo(i,0,m*n)
		arr[i] = true;
	
	cout << "Enter the number of Blocked cells : ";
	ll temp;
	cin >> temp;
	cout << "Enter the positions of Blocked cells (x,y) : \n";
	while(temp--)
	{
		ll x,y;
		cin >> x >> y;
		arr[(x*m)+y] = false;
	}
	
	ll source,sx,sy,dx,dest,dy;
	cout << "Enter Source Coordinates : ";
	cin >> sx >> sy;
	source = (sx*m) + sy;
	cout << "Enter Destination Coordinates : ";
	cin >> dx >> dy;
	dest = (dx*m) + dy;
	
	queue <ll> q;
	ll dist[m*n];
	fo(i,0,m*n)
		dist[i] = -1;
	q.push(source);
	dist[source] = 0;
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp - n < 0 ? false : true) //Element above
		{
			u = temp - n;
			if(arr[u])  //If unblocked
			{
				
				if(dist[u] == -1) //If unvisited
				{
					dist[u] = dist[temp] + 1;
					q.push(u);
				}	
			}
			
		}
		if(temp + n >= (m*n) ? false : true) //Element below
		{
			u = temp + n;
			if(arr[u])
			{
				
				if(dist[u] == -1)	
				{
					dist[u] = dist[temp] + 1;
					q.push(u);
				}	
			}
			
		}
		if(temp % n == 0 ? false : true) //Element to the left
		{
			u = temp - 1;
			if(arr[u])
			{
				
				if(dist[u] == -1)	
				{
					dist[u] = dist[temp] + 1;
					q.push(u);
				}	
			}
			
		}
		if((temp+1) % n == 0 ? false : true) //Element to the right
		{
			u = temp + 1;
			if(arr[u])
			{
				
				if(dist[u] == -1)	
				{
					dist[u] = dist[temp] + 1;
					q.push(u);
				}	
			}
			
		}

	}
	if(dist[dest] == -1) //Destination not visited
	{
		cout << "No Path available from source to destination!";
	}
	else
		cout << "Shortest path from Source to dest is : " << dist[dest];
	return 0;
}