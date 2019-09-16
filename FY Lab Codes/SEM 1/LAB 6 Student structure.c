#include<stdio.h>
#define n 5

struct student
{
	char name[20];
	int roll,marks,age;
}st[n];

int main()
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("Enter details of student %d",i+1);
		printf("\nName : ");
		fflush(stdin);
		gets(st[i].name);
		printf("Roll No : ");
		scanf("%d",&st[i].roll);
		printf("Age : ");
		scanf("%d",&st[i].age);
		printf("Marks : ");
		scanf("%d",&st[i].marks);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\nDetails of student %d",i+1);
		printf("\nName : ");
		puts(st[i].name);
		printf("Roll No : %d",st[i].roll);
		printf("\nAge : %d",st[i].age);
		printf("\nMarks : %d\n",st[i].marks);
	
	}
	return 0;
}
