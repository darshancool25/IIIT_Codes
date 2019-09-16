#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

struct Node *AddToEmpty(struct Node *last, int data) 
{ 

	if (last != NULL) 
		return last; 
	
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
	
	temp -> data = data; 
	last = temp; 
	last -> next = last; 

	return last; 
} 

struct Node *AddBegin(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return AddToEmpty(last, data); 

	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 

	return last; 
} 

struct Node *AddEnd(struct Node *last, int data) 
{ 
	if (last == NULL) 
		return AddToEmpty(last, data); 
	
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 

	temp -> data = data; 
	temp -> next = last -> next; 
	last -> next = temp; 
	last = temp; 

	return last; 
} 

struct Node *AddAfter(struct Node *last, int data, int item) 
{ 
	if (last == NULL) 
		return NULL; 

	struct Node *temp, *p; 
	p = last -> next; 
	do
	{ 
		if (p ->data == item) 
		{ 
			temp = (struct Node *)malloc(sizeof(struct Node)); 
			temp -> data = data; 
			temp -> next = p -> next; 
			p -> next = temp; 

			if (p == last) 
				last = temp; 
			return last; 
		} 
		p = p -> next; 
	} while(p != last -> next); 

	printf("%d Not present in the list!\n",item);
 
	return last; 

} 

void PrintList(struct Node *last) 
{ 
	struct Node *p; 

	if (last == NULL) 
	{ 
		printf("The List is empty!\n");
		
		return; 
	} 
	p = last -> next; 

	do
	{ 
		printf("%d ",p->data);
		p = p -> next; 

	} 
	while(p != last->next); 

} 


int main() 
{ 
	struct Node *last = NULL; 

	last = AddToEmpty(last, 5); 
	last = AddBegin(last, 4); 
	last = AddBegin(last, 66); 
	last = AddEnd(last, 69); 
	last = AddEnd(last, 12); 
	last = AddAfter(last, 10, 69); 

	PrintList(last); 

	return 0; 
} 
