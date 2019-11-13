#include <bits/stdc++.h>

using namespace std;

template <class T>
void BubbleSort(T arr[], int n)
{
	int i, j, flag;
	T temp;
	
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

template <class T>
void printArray(T a[], int n)
{
	for (size_t i = 0; i < n; ++i)
		cout << a[i] << "   ";
	cout << '\n';
}

template <class T1 , class T2>

class tempclass
{
	T1 p;
	T2 q;
public:
	tempclass(T1 a, T2 b)
	{
		p = a;
		q = b;
	}
	void show()
	{
		cout << "<" << p << ", " << q << ">" << '\n';
	}
};

int main()
{
	char array1[] = {'o', 'b', 'j', 'e', 'c', 't'};
	int array2[] = {3, -9, 8, 4, 11, -4};
	int n1, n2;
	n1 = sizeof(array1) / sizeof(array1[0]);
	n2 = sizeof(array2) / sizeof(array2[0]);
	BubbleSort (array1, n1);
	BubbleSort (array2, n2);
	cout << "Sorted Array 1 : ";
	printArray(array1, n1);
	cout << "Sorted Array 2 : ";
	printArray(array2, n2);

	tempclass <int, float> a(12, 9.81);
	tempclass <char, string> b('c', "plusplus");
	a.show();
	b.show();

	return 0;
}