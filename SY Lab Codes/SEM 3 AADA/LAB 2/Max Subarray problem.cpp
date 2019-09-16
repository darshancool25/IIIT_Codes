#include<iostream>

using namespace std;
#define INT_MIN -2147483648

int Kadane(int arr[],int l, int r)
{
	int sum=0;
	int curr_sum=0,i;

	for(i=l;i<=r;i++)
	{
		curr_sum = max(arr[i], curr_sum + arr[i]);
        sum = max(sum, curr_sum);
    
	}
	return sum;
}

int MaxPassing(int arr[],int l, int m, int r)
{
	int sum = 0,i; 
    int l_sum = INT_MIN; 
    for (i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > l_sum) 
          l_sum = sum; 
    } 
  
    
    sum = 0; 
    int r_sum = INT_MIN; 
    for (i = m+1; i <= r; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > r_sum) 
          r_sum = sum; 
    } 
  
    
    return l_sum + r_sum;
}

int MaxSubArray(int arr[],int l,int r)
{
	if(l==r)
		return arr[l];

	else
	{
		int m;
		m = l + (r-l)/2;

		return max((MaxSubArray(arr,l,m),MaxSubArray(arr,m+1,r)),MaxPassing(arr,l,m,r));
	}
}

int main()
{
	
	int n,i;
	cout << "Enter size of array : ";
	cin >> n;

	int arr[n];
	cout << "Enter the array elements : ";
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	cout << "Max Subarray Sum for the given array (Divide & Conquer) is : " << MaxSubArray(arr,0,n-1) << "\n";
	cout << "Max Subarray Sum for the given array (Kadane) is : " << Kadane(arr,0,n-1);

	return 0;
}