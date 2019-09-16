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
	friend void add(Darshan);
};

void add (Darshan d1)
{
	int sum;
	sum = d1.a + d1.b;
	cout << "Sum is : " << sum;

}

int main()
{
	Darshan d1,d2;
	d1.GetData(10,50);
	d2.GetData(50,68);
	add(d1);

	return 0;


}