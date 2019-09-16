#include<stdio.h>



int main()
{
	FILE *fp;
	char name[30];
	int i,n,marks;
	
	printf("Enter name of file to write data : ");
	scanf("%s",&name);
	
	fp=fopen(name,"w");
	
	printf("How many students data do you wish to enter : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Student %d name : ",i+1);
		scanf("%s",&name);
		printf("Student %d marks : ",i+1);
		scanf("%d",&marks);
		fprintf(fp,"Name: %s Marks : %d\n",name,marks);
	}
	printf("\nThe details have been stored in file successfully!!");
	fclose(fp);
	return 0;
	
}
