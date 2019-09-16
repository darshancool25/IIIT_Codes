#include<bits/stdc++.h>

using namespace std;

class student
{
	int MIS,marks,total;
	string name,branch;

public:

	student()
	{
		cout << "Constructor called";
	}

	student(int roll,string temp)
	{
		MIS = roll;
		branch = temp;

	}
	~student()
	{
		cout << "\n" << "Destructor called";
	}
	void getdata();
	void putdata();
	friend void Percentage(student);
};

void student::getdata()
{
	cout << "\n" << "Enter MIS number : ";
	cin >> MIS;
	cout << "Enter name : ";
	cin >> name;
	cout << "Enter your marks : ";
	cin >> marks;
	cout << "Enter total marks : ";
	cin >> total;
}

void student::putdata()
{
	cout << "MIS number : " << MIS << "\n";
	
	cout << "Name : " << name << "\n";

	cout << "Branch : " << branch <<"\n";
	
	cout << "Marks : " << marks << "\n";
	
}

void Percentage(student s)
{
	float per;
	per = ((float)s.marks/(float)s.total) * 100;

	cout << "Percentage obtained is : " << per;
}


int main()
{
	student stu(111810000,"CSE");
	stu.getdata();
	stu.putdata();
	Percentage(stu);

	return 0;

}