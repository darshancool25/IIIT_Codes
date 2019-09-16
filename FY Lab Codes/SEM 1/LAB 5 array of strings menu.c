#include<stdio.h>
int main()
{   int x,i,n;
    char name[10][20];
    printf("Give names of 5 people : ");
    for(i=0;i<5;i++)
    {
       scanf("%s",name[i]);
    }
    printf("enter 1 to view names , 2 to add ,3 to exit\n");
    scanf("%d",&x);
    switch(x)
    {

        case 1:
        {
            for(i=0;i<5;i++)
            {
                printf("%s\n",name[i]);
            }
            break;
        }
        case 2:
        {
            printf("How many names do you wish to add : ");
            scanf("%d",&n);
            printf("\nEnter the names : ");
            for(i=5;i<5+n;i++)
            {
                scanf("%s",&name[i]);
            }
            printf("\nThe names are : ");
            for(i=0;i<5+n;i++)
            {
                printf("%s\n",name[i]);
            }
            break;
        }
        case 3:
        {
            break;
        }
        default :
            printf("Enter a valid input!!");
            break;
    }
    return 0;
}


