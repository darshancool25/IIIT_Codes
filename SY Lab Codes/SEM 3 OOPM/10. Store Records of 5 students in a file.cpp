#include<bits/stdc++.h>
using namespace std;

int main()
{
	ofstream file;
	file.open("A10_File.txt"); 
	int n;
	string str;
	cout << "Enter the number of students : ";
	cin >> n;
	
	for(int i=0 ; i<n ; i++)
	{
		cout << "Enter the Details of student " << i+1 << " :\n";
		file << "Student " << i+1 << '\n';
		cout << "Name : ";
		cin >> str;
		file << "Name : " << str << '\n';
		cout << "MIS : ";
		cin >> str;
		file << "MIS : " << str << '\n';
		cout << "Phone Number : ";
		cin >> str;
		file << "Phone Number : " << str << '\n';
		cout << "Email id : ";
		cin >> str;
		file << "Email id : " << str << "\n\n";
	}
	file.close();
	return 0;
}