#include<iostream>

using namespace std;

void InsertionSort(int arr[],int n)
{
	int i,j,key,outcnt=0,incnt=0;
	
	for(i=1;i<n;i++)
	{
		key = arr[i];
		outcnt++;
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			incnt++;
			arr[j+1] = arr[j];
			arr[j] = key;
			j--;
		}
	}
	cout << "Outer loop ran : " << outcnt << " times\n";
	cout << "Inner loop ran : " << incnt << " times\n";
}

int main()
{
	int arr1[]={1,2,3,4,5,6,7,8,9,10} ,arr2[]={10,9,8,7,6,5,4,3,2,1};

	cout << "For Best case of array of size 10 : \n";
	InsertionSort(arr1,10);
	cout << "For Worst case of array of size 10 : \n";
	InsertionSort(arr2,10);


}