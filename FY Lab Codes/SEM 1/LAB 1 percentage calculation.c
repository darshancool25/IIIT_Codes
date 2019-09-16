#include<stdio.h>
#define exam 200
#define activity 60
#define sports 50
#define w_sports 0.2
#define w_activity 0.3
#define w_exam 0.5

void main()
{
    int ex1,ex2,ac1,ac2,ac3,ex,ac,sp;
    float exp,acp,spp;

    printf("Enter your exam score 1 & 2 : ");
    scanf("%d %d",&ex1,&ex2);
    ex = ex1 + ex2;

    printf("\nEnter your score for Activity 1,2,3 : ");
    scanf("%d %d %d",&ac1,&ac2,&ac3);
    ac = ac1 + ac2 + ac3;

    printf("\nEnter your sports marks : ");
    scanf("%d",&sp);

    //total = (exam*w_exam) + (activity*w_activity) + (sports*w_sports)
    exp =((float)(ex)*w_exam/exam)*100;
    acp = ((float)(ac)*w_activity/activity)*100;
    spp = ((float)(sp)*w_sports/sports)*100;
    printf("\nExam percentage : %f",exp);
    printf("\nActivity Percentage : %f",acp);
    printf("\nSports Percentage : %f",spp);

    printf("\nTotal percentage is : %f",exp+acp+spp);

}

