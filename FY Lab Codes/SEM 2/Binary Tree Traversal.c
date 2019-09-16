#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 

 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 



void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
  
    
     printPostorder(node->left); 
  

     printPostorder(node->right); 
  

     printf("%d ", node->key); 
} 
  

void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
   
     printInorder(node->left); 
  
   
     printf("%d ", node->key);   
  
  
     printInorder(node->right); 
} 
  

void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
 
     printf("%d ", node->key);   
  

     printPreorder(node->left);   
  
   
     printPreorder(node->right); 
} 


struct node* insert(struct node* node, int key) 
{ 

	if (node == NULL) return newNode(key); 


	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 

	
	return node; 
}


int main() 
{ 
	
	struct node *root = NULL; 
	root = insert(root, 7); 
	insert(root, 2); 
	insert(root, 1); 
	insert(root, 3); 
	insert(root, 9); 
	insert(root, 8); 
	insert(root, 10);

	printf("\nPreorder traversal of binary search tree is \n"); 
    printPreorder(root); 
  
    printf("\nInorder traversal of binary search tree is \n"); 
    printInorder(root);  
  
    printf("\nPostorder traversal of binary search tree is \n"); 
    printPostorder(root); 


	return 0; 
} 
