#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll 			long long int
#define ld 			long double
#define mk 			make_pair
#define pb 			push_back
#define f			first
#define s			second
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)
#define MOD			1000000007

using namespace std;
void DDA(ld x1, ld y1, ld x2, ld y2)
{
	ld step = max(abs(x1 - x2), abs(y1 - y2));
	ld xinc, yinc;
	xinc = (x2 - x1) / step;
	yinc = (y2 - y1) / step;
	ld x = x1, y = y1;
	ll i;
	fo(i, 0, step)
	{
		cout << (ll)x << ' ' << (ll)y << '\n';
		x += xinc;
		y += yinc;
	}
	cout << (ll)x << ' ' << (ll)y;
}

int main()
{
	// boost;
	cout << "Enter the coordinates of : ";
	ld x1, x2, y1, y2;
	cout << "\nPoint 1 : ";
	cin >> x1 >> y1;
	cout << "\nPoint 2 : ";
	cin >> x2 >> y2;
	DDA(x1, y1, x2, y2);

}