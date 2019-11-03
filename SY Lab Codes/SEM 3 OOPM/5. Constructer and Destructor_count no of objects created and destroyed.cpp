#include<iostream>

using namespace std;

int objc = 0;
int objd = 0;

class Darshan
{
public:
	Darshan()
	{
		cout << "Default Constructer called\n";
		objc++;
	}
	Darshan(int a)
	{
		cout << "Paameterized Constructer called\n";
		objc++;
	}
	Darshan(Darshan &d)
	{
		
		cout << "Copy Constructer called\n";
		objc++;
	}
	~Darshan()
	{
		cout << "Destructor called\n";
		objd++;
	}
};

int main()
{
	Darshan d1,d2(68);
	Darshan d3(d2);

	cout << "No. of objects created : " << objc << endl;
	// cout << "No. of objects Destructed : " << objd <<endl;
	return 0;
}