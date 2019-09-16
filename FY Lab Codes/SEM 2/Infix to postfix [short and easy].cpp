#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[500];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
}

int main()
{
	int i;
    char str[100];
    char x;
    printf("Enter the expression :: ");
    scanf("%s",str);
    for(i=0;i<strlen(str);i++)
    {
        if(isalnum(str[i]))
            printf("%c",str[i]);
        else if(str[i] == '(')
            push(str[i]);
        else if(str[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(str[i]))
                printf("%c",pop());
            push(str[i]);
        }

    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
