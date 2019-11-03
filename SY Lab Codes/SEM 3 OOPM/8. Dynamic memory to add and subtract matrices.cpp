#include<iostream>
using namespace std;

int main()
{
	int **p[4];
	int i,j;
	for(i=0;i<4;i++)
	{
		p[i] = new int*[3];
		for(j=0;j<3;j++)
		{
			p[i][j] = new int [3];
		}
	} 
	cout << "Input the first 3*3 matrix :\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin >> p[0][i][j];
		}	
	}
	cout << "Input the second 3*3 matrix :\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin >> p[1][i][j];
		}	
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			p[2][i][j] = p[0][i][j] + p[1][i][j];
			p[3][i][j] = p[0][i][j] - p[1][i][j];
		}	
	}
	cout << "Addition of Matrices : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout << p[2][i][j] << ' ';
		cout << '\n';
	}
	cout << "Subtraction of Matrices : \n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			cout << p[3][i][j] << ' ';
		cout << '\n';
	}
	return 0;
}