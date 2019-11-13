#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll 			int
#define mk 			make_pair
#define pb 			push_back
#define f			first
#define s			second
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)
#define MOD			1000000007

using namespace std;
void swap (int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
void randomize ( int arr[], ll n ) 
{ 
    srand ( time(NULL) ); 
    for (int i = n-1; i > 0; i--) 
    { 
        int j = rand() % (i+1); 
        swap(&arr[i], &arr[j]); 
    } 
}

int main()
{
	// boost;
	freopen("IN.txt", "w", stdout);
  ll n;
  cin >> n;
	int arr[n*n];
	ll i,j;
	for(i=0;i<(n*n);i++)
    {
        arr[i]=i+1;
    }
    randomize(arr,n*n);
    fo(i,0,n)
   	{
   		fo(j,0,n)
   			cout << arr[(i*n)+j] << ' ';
   		  cout << '\n';
   	}

}