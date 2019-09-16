#include<stdio.h>
# define male 0.05
# define fem 0.1
# define extra 0.02

int main()
{
    float rate, total;
    int sal;
    char s;

    printf("\nEnter your sex (m/f) : ");
    scanf("%c",&s);

    printf("Enter your salary : ");
    scanf("%d",&sal);



    if(s=='m')
    {
        if(sal>10000)
            rate = male;

        else
            rate = male + extra;
    }

    if(s=='f')
    {
        if(sal>10000)
            rate = fem;

        else
            rate = fem + extra;
    }

    printf("\nYour Bonus : %f",sal*rate);
    total = sal + (sal*rate);
    printf("\ntotal salary with bonus : ",total);

    return 0;

}

