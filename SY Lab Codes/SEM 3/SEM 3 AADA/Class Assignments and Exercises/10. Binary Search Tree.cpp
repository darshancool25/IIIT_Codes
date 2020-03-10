#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll 			long long int
#define mk 			make_pair
#define pb 			push_back
#define f			first
#define s			second
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)
#define MOD			1000000007

using namespace std;

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


void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
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

struct node* search(struct node* root, int key)
{

	if (root == NULL || root->key == key)
		return root;


	if (root->key < key)
		return search(root->right, key);


	return search(root->left, key);
}
struct node * minValueNode(struct node* node)
{
	struct node* current = node;
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* root, int key)
{

	if (root == NULL) return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else
	{

		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);


		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}



int main()
{

	struct node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);


	inorder(root);
	int key;
	printf("\nEnter Element you wish to search : ");
	scanf("%d", &key);

	if (search(root, key))
	{
		printf("\nElement found in the tree!");

	}
	else
	{
		printf("\nElement not found in the tree");
	}

	cout << "\nEnter node you wish to delete : ";
	cin >> key;
	if (search(root, key))
		root = deleteNode(root, key);
	cout << '\n';
	inorder(root);


	return 0;
}
