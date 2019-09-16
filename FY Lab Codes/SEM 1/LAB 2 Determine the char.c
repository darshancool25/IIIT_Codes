#include<stdio.h>
#include<ctype.h>

int main()
{
    char ch;

    printf("Enter a character : ");
    scanf("%c",&ch);

    printf("\nYou have entered ");
    if(isalpha(ch))
    printf("alphabet");

    if(isdigit(ch))
    printf("Integer");

    if(ispunct(ch))
    printf("punctuation");

    if(isspace(ch))
    printf("space");

    return 0;
}
