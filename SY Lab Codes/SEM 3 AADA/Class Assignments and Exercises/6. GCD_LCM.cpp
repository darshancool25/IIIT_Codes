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
ll Gcd(ll a, ll b)
{
	if(b==0)
	return a;
	
	else
	return Gcd(b,a%b);
}

int main()
{
	// boost;4
	ll a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	ll gcd = Gcd(max(a,b),min(a,b));
	cout << "GCD : " << gcd << '\n';
	cout << "LCM : " << (a*b)/gcd;
	return 0;


}