#include<bits/stdc++.h>
#define ll 			long long int

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

	ll a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	ll gcd = Gcd(max(a,b),min(a,b));
	cout << "GCD : " << gcd << '\n';
	cout << "LCM : " << (a*b)/gcd;
	return 0;


}