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

void BubbleSort(ll arr[], ll n)
{
	ll i, j, flag, temp;
	//main iterator loop
	for (i = 0; i < n - 1; i++)
	{

		flag = 0;
		//compare every two adjacent elements
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//swap the two numbers
				flag = 1;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag == 0)
		{
			//array is sorted as no swaps took place in whole iteration
			break;
		}
	}

}

int main()
{

	ll n, i;
	cout << "Enter the number of elements : ";
	cin >> n;

	ll a[n];
	cout << "\nEnter the Elements : ";
	for (i = 0; i < n; i++)
		cin >> a[i];

	BubbleSort(a, n);

	cout << "\nThe Sorted array is :";
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}

