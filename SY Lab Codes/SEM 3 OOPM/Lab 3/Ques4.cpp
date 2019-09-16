#include<iostream>

using namespace std;

class Darshan
{
	int a,b;

public:
	void GetData(int x, int y)
	{
		a = x;
		b = y;
	}
	void putdata()
	{
		cout << a << " " << b;
	}
	friend void add(Darshan);
	Darshan operator - ();
};

void add (Darshan d1)
{
	int sum;
	sum = d1.a + d1.b;
	cout << "Sum is : " << sum;

}

Darshan Darshan::operator - ()
{
	Darshan dd;
	dd.a = -a;
	dd.b = -b;
	return dd;
}

int main()
{
	Darshan d1,d2,d3;
	d1.GetData(10,50);
	d2.GetData(50,68);
	d3 = -d2;
	d3.putdata();
	add(d1);

	return 0;


}