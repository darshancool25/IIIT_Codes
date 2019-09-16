#include<stdio.h>
# define tax1 0;
# define tax2 0.2;
# define tax3 0.3;
# define tax4 0.4;

int main()
{
    int sal;
    float rate;

    printf("Enter your salary : ");
    scanf("%d",&sal);

    if(sal<150000)
        rate=tax1;

    if(sal<300000 && sal>=150000)
        rate=tax2;

    if(sal>=300000 && sal<500000)
        rate=tax3;

    if(sal>=500000)
        rate=tax4;

    printf("\nThe total calculated Tax is : %f", (float)(sal*rate));
    printf("\nYour income after tax deduction : %f", (float)(sal - ((sal*rate))));
}
