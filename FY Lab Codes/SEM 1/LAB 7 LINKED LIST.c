#include<stdio.h> 
#include<stdlib.h> 
  
struct Node  
{ 
  int data; 
  struct Node *next; 
}; 
  

void PrintList(struct Node *n) 
{ 
  while (n != NULL) 
  { 
     printf("%d ", n->data); 
     n = n->next; 
  } 
} 

void Push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

void InsertAfter(struct Node *prev_node, int new_data)
{
	if(prev_node==NULL)
	{
		printf("The given previous node cannot be NULL\n");
		return;
	}
	
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	
	new_node->data=new_data;
	new_node->next=prev_node->next;
	prev_node->next=new_node;
	return;
	
	
}

void InsertAfterPos(struct Node* head, int pos, int new_data)
{
	int cnt=1;
	if(head==NULL)
	{
		printf("Given Node cannot be NULL\n");
		return;
	}
	struct Node *temp=head;
	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	while(cnt!=pos)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next!=NULL)
	{
		new_node->next=temp->next;
	}
	else
	{
		new_node->next=NULL;
	}
	temp->next=new_node;
}

void Append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	struct Node *last = *head_ref;
	
	new_node->data=new_data;
	new_node->next=NULL;
	
	if(*head_ref==NULL)
	{
		*head_ref = new_node;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
	return;
}
void DeleteNode(struct Node** head_ref, int key)
{
	struct Node* temp=*head_ref, *prev;
	
	if(temp!=NULL && temp->data==key)
	{
		*head_ref=temp->next;	//changed head
		free(temp);  //free the old head
		return;
	}
	
	while(temp!=NULL && temp->data!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	
	if(temp==NULL)
	return;
	
	prev->next=temp->next;
	
	free(temp);
	
}

void DeletePos(struct Node** head_ref, int pos)
{
	if(*head_ref==NULL)
	{
		printf("Head ref is NULL.....\n");
		return;
	}
	
	struct Node *temp=*head_ref;
	int i;
	
	if(pos==1)
	{
		*head_ref=temp->next;
		free(temp);
		return;
	}
	
	for(i=1;temp!=NULL && i<pos-1;i++)
	{
		temp=temp->next;
	}
	
	if(temp==NULL || temp->next==NULL)
	{
		return;
	}
	
	struct Node* next=temp->next->next;
	
	free(temp->next);
	
	temp->next=next;
	
	
}
  
int main() 
{ 
  struct Node* head = NULL; 
  struct Node* second = NULL; 
  struct Node* third = NULL; 
    
    
  head  = (struct Node*)malloc(sizeof(struct Node));  
  second = (struct Node*)malloc(sizeof(struct Node)); 
  third  = (struct Node*)malloc(sizeof(struct Node)); 
   
  head->data = 1; 
  head->next = second;    
   
  second->data = 2; 
  second->next = third;   
   
  third->data = 3; 
  third->next = NULL; 
    
  PrintList(head);
  
  Push(&head,69); //Adds element at beginning of the link list
  printf("\n");
  PrintList(head); 
  InsertAfter(second,669); //adds element after Node*second (not after position 2nd)!
  printf("\n");
  PrintList(head);
  InsertAfterPos(head,3,555);  //adds element at after pos==3, i.e at pos=4;
  printf("\n");
  PrintList(head);
  Append(&head,111);  //appends 111 at end of linked list
  printf("\n");
  PrintList(head);
  DeleteNode(&head,555);   // deletes first occurence of 555 in linked list
  printf("\n");
  PrintList(head);
  DeletePos(&head,5);   // deletes elem at pos==5;  Note : Positions are 1,2,3....
  printf("\n");
  PrintList(head);
   
  return 0; 
}
