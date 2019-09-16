#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
 int top;
 unsigned capacity;
 int* array;
};

struct Stack* createStack( unsigned capacity )
{
 struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 if (!stack)
 return NULL;
 stack->top = -1;
 stack->capacity = capacity;
 stack->array = (int*) malloc(stack->capacity * sizeof(int));
if (!stack->array)
 return NULL;
 return stack;
}

int isEmpty(struct Stack* stack)
{
 return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
 return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
 if (!isEmpty(stack))
 return stack->array[stack->top--] ;
 return '$';
}
void push(struct Stack* stack, char op)
{
 stack->array[++stack->top] = op;
}


int main()
{
	struct Stack* stack = createStack(10);
	int temp;
	printf("Enter an element to push into stack : ");
	scanf("%d",&temp);
	push(stack,temp);
	printf("Enter an element to push into stack : ");
	scanf("%d",&temp);
	push(stack,temp);
	printf("Enter an element to push into stack : ");
	scanf("%d",&temp);
	push(stack,temp);
	printf("Enter an element to push into stack : ");
	scanf("%d",&temp);
	push(stack,temp);

	printf("Popped : %d",pop(stack));
	printf("Popped : %d",pop(stack));





	return 0;
}