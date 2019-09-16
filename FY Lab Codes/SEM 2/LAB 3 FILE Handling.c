#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main()
{
	FILE *fp;
	char ch,fname[30],str[50];
	int mis;

	printf("Enter the file name(with extension) you wish to create : ");
	scanf("%s",&fname);

	fp=fopen(fname,"w");

	printf("File opened successfully....Enter the data you wish to save in the file");
	printf("\nOnce you have entered the data press EOF : \n");
	fflush(stdin);
	while((ch=getchar())!=EOF)
	{
		putc(ch,fp);
	}
	printf("\nData Saved into file successfully!");
	fclose(fp);
	printf("\nYour file data is as follows : \n");
	fflush(stdin);
	
	fp=fopen(fname,"r");
	while((ch=getc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	fclose(fp);
	
	fp=fopen(fname,"a");
	printf("\nEnter a string to append in the file : \n");
	fflush(stdin);
	gets(str);
	fputs(str,fp);
	printf("\nString appended in the file successfully!");
	fclose(fp);
	
	printf("\nNow enter your details : ");
	fp=fopen(fname,"a");
	
	printf("\nStudent name : ");
	fflush(stdin);
	gets(str);
	printf("Student MIS : ");
	scanf("%d",&mis);
	fprintf(fp,"\nName: %s. MIS : %d\n",str,mis);
	printf("\nStudent details stored in file Successfully!");
	fclose(fp);
	return 0;
}