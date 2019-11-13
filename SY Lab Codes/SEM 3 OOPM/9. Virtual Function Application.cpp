#include<iostream>
using namespace std;

class A
{
public:
	virtual void Display()
	{
		cout << "Base Display!";
	}
};

class B:public A
{
public:
	void Display()
	{
		cout << "Derived Display!";
	}
};

int main()
{
	A *p;
	B b;
	p = &b;
	p ->Display();
	return 0;
}