#include<stdio.h>
#include<string.h>

struct str
{
	char name[50];
	int height;
};

int main()
{
	struct str a[5],b[5];
	FILE *fptr;
	
	int i;
	
	fptr=fopen("lab8file5.txt","wb");
	
	for(i=0;i<5;i++)
	{
		printf("Record %d\n",i+1);
		printf("Enter Name : ");
		fflush(stdin);
		gets(a[i].name);
		printf("Enter height : ");
		scanf("%d",&a[i].height);
	}
	
	fwrite(a,sizeof(a),1,fptr);
	
	fclose(fptr);
	fptr=fopen("lab8file5.txt","rb");
	fread(b,sizeof(b),1,fptr);
	for(i=0;i<5;i++)
	{
		printf("Record %d : \n",i+1);
		printf("Name : %s",b[i].name);
		printf("\nHeight : %d",b[i].height);
	}
	fclose(fptr);


	
	return 0;
}
