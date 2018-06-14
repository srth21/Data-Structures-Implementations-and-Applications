#include<stdio.h>
#include<stdlib.h>


/*

Reverse Inorder Traversal

Traverse the Right Node first
Have a variable to count number of nodes traversed
we traverse from the largest to the smallest nodes
thus when we have traversed k nodes, we have reached the kth largest element

*/

struct node
{
	int val;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

int insert(int val, Node** root)
{
	Node *temp,*prev,*curr;

	temp=(Node *)malloc(sizeof(Node));

	temp->val=val;
	temp->left=NULL;
	temp->right=NULL;

	curr=*root;
	prev=NULL;

	if(curr==NULL)
	{
		*root=temp;
		return 1;
	}

	while(curr!=NULL)
	{
		prev=curr;
		if(val<curr->val)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}

	if(val<prev->val)
	{
		prev->left=temp;
		return 1;
	}
	prev->right=temp;
	return 1;
}

void reverseInorderWithCount(Node *root, int *c, int k)
{
	if(root!=NULL)
	{
		reverseInorderWithCount(root->right,c,k);

		*c=*c+1;

		if(*c==k)
		{
			printf("%d Largest Element is : %d\n",k,root->val);
		}

		reverseInorderWithCount(root->left,c,k);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	Node *root;

	root=(Node *)malloc(sizeof(Node));
	root=NULL;

	int x=insert(10,&root);
	x=insert(9,&root);
	x=insert(12,&root);
	x=insert(7,&root);
	x=insert(11,&root);
	x=insert(14,&root);

	int c=0;
	reverseInorderWithCount(root,&c,2);
	return 0;
}