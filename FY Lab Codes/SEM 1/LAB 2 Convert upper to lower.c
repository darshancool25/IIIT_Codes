#include<stdio.h>

int main()
{
    char ch;

    printf("Enter a character : ");
    scanf("%c",&ch);

    if(ch>='a' && ch<='z')
        printf("%c", ch-32);

    if(ch>='A' && ch<='Z')
        printf("%c", ch+32);


}
