#include<iostream>
using namespace std;

class Student
{
	string email,fname, lname;
	long long int m[3],num,MIS;
public:
	Student()
	{

	}
	void GetData()
	{
		cout << "Enter your first name and last name : ";
		cin >> fname >> lname;
		cout << "Enter your MIS Number : ";
		cin >> MIS;
		cout << "Enter your marks obtained in 3 subjects : ";
		cin >> m[0] >> m[1] >> m[2];
		cout << "Enter your contact Number : ";
		cin >> num;
		cout << "Enter your email id : ";
		cin >> email;
	}
	void Putdata()
	{
		cout << "::::Student details are as follows::::\n";
		cout << "Name : " << fname << ' ' << lname << '\n';
		cout << "MIS Number : " << MIS << '\n';
		cout << "Marks obtained : " << m[0] << ' ' << m[1] << ' ' <<  m[2] << '\n';
		cout << "Contact Number : " << num << '\n';
		cout << "Email id : " << email << '\n';

	}
	void Average()
	{
		cout << "Average marks of MIS " << MIS << " is : " << (m[0]+m[1]+m[2])/3 << '\n';
	}
};

int main()
{
	Student s1;
	s1.GetData();
	s1.Putdata();
	s1.Average();
	return 0;
}