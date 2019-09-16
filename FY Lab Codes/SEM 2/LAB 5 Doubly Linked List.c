#include <stdio.h> 
#include <stdlib.h> 
  

struct Node 
{ 
    int data; 
    struct Node* next; 
    struct Node* prev; 
};

void PrintList(struct Node* node) 
{ 
    struct Node* last; 
    printf("\nTraversing in forward direction \n"); 
    while (node != NULL) { 
        printf(" %d ", node->data); 
        last = node; 
        node = node->next; 
    } 
  
    printf("\nTraversing in reverse direction \n"); 
    while (last != NULL) { 
        printf(" %d ", last->data); 
        last = last->prev; 
    } 
} 

void Push(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));   

    new_node->data = new_data; 
  	new_node->next = (*head_ref); 
    new_node->prev = NULL; 
  

    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node;   
    
    (*head_ref) = new_node; 
}

void InsertAfter(struct Node* prev_node, int new_data) 
{ 
    
    if (prev_node == NULL) 
    { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
   	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  	
  	new_node->data = new_data; 
  	new_node->next = prev_node->next; 
  	prev_node->next = new_node; 
 	new_node->prev = prev_node; 
  
	if (new_node->next != NULL) 
        new_node->next->prev = new_node; 
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
		new_node->prev = temp;
		(new_node->next)->prev=new_node;
	}
	else
	{
		new_node->next=NULL;
		new_node->prev = temp;
	}
	temp->next=new_node;
}

void Append(struct Node** head_ref, int new_data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));   
    struct Node* last = *head_ref;   
    
    new_node->data = new_data;   
   
    new_node->next = NULL;   
   
    if (*head_ref == NULL) 
    { 
        new_node->prev = NULL; 
        *head_ref = new_node; 
        return; 
    }   
  
    while (last->next != NULL) 
        last = last->next; 
  	
  	last->next = new_node; 
    new_node->prev = last; 
  
    return; 
}

void DeleteAhead(struct Node** head_ref)
{
	if(*head_ref==NULL)
	{
		printf("Head ref is NULL.....\n");
		return;
	}
	struct Node *temp=*head_ref;
	*head_ref=temp->next;
	(*head_ref)->prev=NULL;
	free(temp);
	return;
}



int main()

{
	struct Node* head = NULL;

	Append(&head,123);
	Push(&head,111);
	Push(&head,6969);
	PrintList(head);
	DeleteAhead(&head);
	PrintList(head);
	InsertAfterPos(head,1,85);
	PrintList(head);

	return 0;
}