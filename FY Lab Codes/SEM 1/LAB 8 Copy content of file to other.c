#include<stdio.h>

int main()
{
	FILE *fp1,*fp2;
	char ch,fname[30];
	
	printf("Enter the file name for Reading : ");
	scanf("%s",&fname);
	
	fp1=fopen(fname,"r");
	
	printf("\nEnter the file name for writing : ");
	scanf("%s",&fname);
	
	fp2=fopen(fname,"w");
	
	if(fp2==NULL)
	{
		printf("\nCannot open file %s for writing",fname);
		return 0;
	}
	
	ch=fgetc(fp1);
	
	while(ch!=EOF)
	{
		fputc(ch,fp2);
		ch=fgetc(fp1);
	}
	printf("\nThe contents have been copied to %s",fname);
	
	fclose(fp1);
	fclose(fp2);
	return 0;
	
}
