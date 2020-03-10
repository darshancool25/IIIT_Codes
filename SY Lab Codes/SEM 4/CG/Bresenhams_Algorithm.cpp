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

void Bresenhams(ll x1, ll y1, ll x2, ll y2)
{
	ll x, y, xdiff = (x2 - x1), ydiff = (y2 - y1);
	x = x1;
	y = y1;
	ll p = 2 * ydiff - xdiff;
	while (x <= x2)
	{
		cout << x << ' ' << y << '\n';
		x++;
		if (p < 0) p += 2 * ydiff;
		else
		{
			p += 2 * ydiff - 2 * xdiff;
			y++;
		}
	}
}



int main()
{
	// boost;
	cout << "Enter the coordinates of : ";
	ll step, x1, x2, y1, y2;
	cout << "\nPoint 1 : ";
	cin >> x1 >> y1;
	cout << "Point 2 : ";
	cin >> x2 >> y2;
	Bresenhams(x1, y1, x2, y2);

	return 0;

}