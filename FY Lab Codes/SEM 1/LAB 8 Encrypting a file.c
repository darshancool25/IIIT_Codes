#include<stdio.h>

int main()
{
	FILE *fp1,*fp2;
	char ch;
	
	fp1=fopen("lab8decrypted.txt","r");
	fp2=fopen("lab8encrypted.txt","w");
	
	if(fp2==NULL)
	{
		printf("Target file not found");
		return 0;
	}
	while(1)
	{
		ch=fgetc(fp1);
		if(ch==EOF)
		{
			printf("End of file reached!");
			break;
		}
		else
		{
			ch=ch-(69*6-9);
			fputc(ch,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
