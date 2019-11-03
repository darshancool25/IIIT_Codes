#include<iostream>
using namespace std;

class Complex
{
	int real,imag;

public:	
	Complex()
	{

	}

	Complex(int r, int c)
	{
		real = r;
		imag = c;
	}

	Complex operator +(Complex c2);
	void Display()
	{
		cout << "Real : " << real << " Imaginary : " << imag << '\n';
	}
};

	Complex Complex::operator +(Complex c2)
	{
		Complex c;
		c.real = real + c2.real;
		c.imag = imag + c2.imag;
		return c;
	}

int main()
{
	Complex c1(2,3),c2(4,5),c3;
	c1.Display();
	c2.Display();
	c3 = c1+c2;
	c3.Display();
	return 0;
}