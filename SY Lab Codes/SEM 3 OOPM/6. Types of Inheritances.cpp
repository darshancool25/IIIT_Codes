#include<bits/stdc++.h>

using namespace std;
class person
{
protected:
	int code;
public:
	string name;
	void getdata()
	{
		cout << "Enter the name : " << '\n';
		cin >> name;
		cout << "Enter code : " << '\n';
		cin >> code;
	}
};
class admin: virtual public person
{
protected:
	int exp;
public:
	void input()
	{
		cout << "Enter experience in years : " << '\n';
		cin >> exp;
	}
};
class account: virtual public person
{
protected:
	int pay;
public:
	void get()
	{
		cout << "Enter pay of employee : " << '\n';
		cin >> pay;
	}
};
class master: public admin, public account
{
public:
	void showdata()
	{
		cout << "Name of the employee : " << name << '\n';
		cout << "Code of the employee : " << code << '\n';
		cout << "Experience of the employee : " << exp << '\n';
		cout << "Pay of the employee : " << pay << '\n';
	}
};
int main()
{
	master m1, m2;
	m1.getdata();
	m1.input();
	m1.get();
	m1.showdata();

	m2.getdata();
	m2.input();
	m2.get();
	m2.showdata();

	return 0;
}
