#include<stdio.h>
#include<stdlib.h>

//Pointer to structure with dynamic memory allocation using malloc

struct student
{
	char name[20];
	int roll;
	float marks;
} *st;

int main()
{
	int num,i;
	printf("Enter number of records : ");
	scanf("%d",&num);
	
	st = (struct student *)malloc(num*sizeof(struct student));
	for(i=0;i<num;i++)
	{
		printf("\nEnter Record number %d",i+1);
		printf("\nEnter name : ");
		fflush(stdin);
		gets((st+i)->name);
		printf("Enter roll no : ");
		scanf("%d",&(st+i)->roll);
		printf("Enter your marks : ");
		scanf("%f",&(st+i)->marks);
	}
	
	for(i=0;i<num;i++)
	{
		printf("\nRECORD NO. %d",i+1);
		printf("\nName : ");
		puts((st+i)->name);
		printf("Roll no. : %d",(st+i)->roll);
		printf("\nMarks : %f\n",(st+i)->marks);
		
	}
	
}
