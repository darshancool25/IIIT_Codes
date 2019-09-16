#include<stdio.h>

void Area(float *rad, float *area);

int main()
{
    float rad,area;

    printf("Enter the radius of the circle : ");
    scanf("%f",&rad);

    Area(&rad,&area);

    printf("\nThe Area of the circle is : %f",area);

    return 0;
}

void Area(float *rad, float *area)
{
    *area = 3.14*(*rad)*(*rad);
}
