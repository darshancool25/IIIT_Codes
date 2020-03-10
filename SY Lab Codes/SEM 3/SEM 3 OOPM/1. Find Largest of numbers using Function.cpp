#include <iostream>
using namespace std;

int largest(int arr[], int n)
{	int i; int max = arr[0];
	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
int main()
{
	int arr[] = {10, 324, 45, 90, 9808}; int n;
	cout << "Enter number of elements: ";
	cin >> n;
	arr[n];
	for (int i = 0; i < n; i++)
	{
		int temp; cin >> temp; arr[i] = temp;
	}
	cout << "Largest number is " << largest(arr, n);
	return 0;
}