#include<stdio.h>

int main()
{
	FILE *fp1,*fp2;
	char ch1,ch2;
	char fname1[30],fname2[30];
	
	printf("Enter name of first file : ");
	scanf("%s",&fname1);
	
	printf("Enter name of second file : ");
	scanf("%s",&fname2);
	
	fp1=fopen(fname1,"r");
	fp2=fopen(fname2,"r");
	
	if(fp1==NULL)
	{
		printf("\nCannot open %s for reading",fname1);
		return 0;
	}
	
	else if(fp2==NULL)
	{
		printf("\nCannot open %s for reading",fname2);
		return 0;
	}
	
	else
	{
		ch1=getc(fp1);
		ch2=getc(fp2);
		
		while((ch1!=EOF)&&(ch2!=EOF)&&(ch1==ch2))
		{
			ch1=getc(fp1);
			ch2=getc(fp2);
		}
		
		if(ch1==ch2)
		{
			printf("\nThe two files are identical");
		}
		else
		{
			printf("\nThe two file are not identical");
		}
		fclose(fp1);
		fclose(fp2);
	}
	return 0;
}
