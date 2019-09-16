#include<stdio.h>
#include<math.h>
#define pi 3.142

void main()
{
    float radius, area;

    printf("Enter the radius of the circle \n");
    scanf("%f",&radius);

    area = pi*pow(radius,2);
    printf("Area of the circle is = %5.2f\n",area);
}
