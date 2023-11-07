#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*root;
void insert();
void preorder(struct node *root);
void inorder(struct node *root);
void postorder(struct node *root);
struct node* minValueNode(struct node *curr);
struct node *delet(struct node *root, int item);
void search();
int main()
{
	int choice,item;
	while(1)
	{
		printf("\nMENU\n---------\n1.insertion\n2.Deletion\n3.Preorder\n4.Inorder\n5.postorder\n6.search\n7.exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert();
			break;
			case 2:printf("enter the value to be deleted\n");
			scanf("%d",&item);
			delet(root,item);
			break;
			case 3: printf("The Preorder Traversal is:\n");
			preorder(root);
			break;
			case 4: printf("The Inorder Traversal is:\n");
			inorder(root);
			break;
			case 5: printf("The Postorder Traversal is:\n");
			postorder(root);
			break;
			case 6: search();
			break;
			case 7: exit(0);
			default: printf("\n invalid choice");
		}
	}
}

void insert()
{
	int item;
	struct node *current, *pre, *newnode;
	printf("Enter the value of node\n");
	scanf("%d",&item);
	if(root==NULL)
	{
		root=(struct node*)malloc(sizeof(struct node*));
		root->data=item;
		root->left==NULL;
		root->right==NULL;
		printf("Node is inserted\n");
	}
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=item;
		newnode->left=NULL;
		newnode->right=NULL;
		current=root;
		// find the last node  for insertion
		while(current!=NULL)
		{
			pre=current;
			if(current->data<=item)
				current=current->right;
			else
				current=current->left;
		}
		// check whether value greater than or less than last node
		if(pre->data<=item)
			pre->right=newnode;
		else
			pre->left=newnode;
		printf("Node is inserted\n");
	}
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}

void search()
{
	int item,flag=0;
	struct node *current;
	printf("Enter the item to search\n");
	scanf("%d",&item);
	current=root;
	while(current!=NULL)
	{
		if(current->data==item)
		{
			flag=1;
			printf("%d found\n",item);
			return;
		}
		else if(current->data<item)
			current=current->right;
		else
			current=current->left;
	}
	if(flag==0)
		printf("%d not found\n",item);
}

struct node *delet(struct node *root, int item)
{
	struct node *curr;
	if (root == NULL)

		return 0;

	else if (item < root->data)

		root->left= delet(root->left,item);

	else if (item > root->data)

		root->right= delet(root->right,item);

	else
	{
		//delete node with one or zero child
		if(root->left==NULL)
		{
			curr=root->right;
			free(root);
			return curr;
		}
		else if(root->right==NULL)
		{
			curr=root->left;
			free(root);
			return curr;
		}
		else
		{
			//delete node with two child
			struct node *curr=minValueNode(root->right);

			root->data=curr->data;

			root->right=delet(root->right,curr->data);

		}
	}
	return root;

}

struct node* minValueNode(struct node *curr){

	while(curr->left!=NULL){
		curr=curr->left;
	} 
	return curr;
}






















