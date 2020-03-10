#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout << "Enter the size of array : ";
	cin >> n;
	int arr[n];
	cout << "Enter the array elements : ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int index;
	cout << "Enter the index of required element: ";
	cin >> index;
	try {
		if (index > n - 1) {
			throw - 1;
		}
		else {
			cout << "Element at index  " << index << " is: " << arr[index];
		}
	}
	catch (int) {
		cout << "Index  " << index << " is out of bounds!" << endl;
	}
	return 0;
}
