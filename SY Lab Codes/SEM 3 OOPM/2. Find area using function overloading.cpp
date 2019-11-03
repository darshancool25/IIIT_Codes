#include<iostream>
#include<math.h>

using namespace std;

double area(double radius)
{
	return 3.14 * radius * radius;
}

double area(double l, double b)
{
	return l*b;
}

double area(double a, double b, double c)
{
	double s;
	s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
	cout << "Circle : " << area(5.00) << "\n";
	cout << "Rectangle : " << area(5.00, 10.00) << "\n";
	cout << "Triangle : " << area(5.00,4.00,3.00) << "\n";
	return 0;
}