#include<bits/stdc++.h>
#define ll 			long long int
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)

using namespace std;

int main()
{
	ll m,n,y,z,i,j,k;
	cout << "Enter dimensions of Matrix 1 : ";
	cin >> m >> n;
	cout << "Enter the dimensions of Matrix 2 : ";
	cin >> y >> z;
	if(n==y)
	{
		ll arr1[m][n],arr2[y][z];
		cout << "Enter elements of Matrix 1: ";
		fo(i,0,m)
			fo(j,0,n)
				cin >> arr1[i][j];
		cout << "Enter elements of Matrix 2: ";
		fo(i,0,y)
			fo(j,0,z)
				cin >> arr2[i][j];
		ll mul[m][z];
		fo(i,0,m)
		{
			fo(j,0,z)
			{
				mul[i][j] = 0;
				fo(k,0,n)
					mul[i][j] += arr1[i][k]*arr2[k][j];
			}
		}

		cout << "Matrix 1 * Matrix 2 : \n";
		fo(i,0,m)
		{
			fo(j,0,z)
				cout << mul[i][j] << ' ';
			cout << '\n';
		}		
	}
	else
	{
		cout << "\nCant Multiply the given two matrices : ";
	}

}