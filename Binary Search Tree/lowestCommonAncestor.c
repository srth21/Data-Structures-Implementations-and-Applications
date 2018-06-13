#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
};

typedef struct node node;

node *newNode(int val)
{
	node *n;
	n=(node *)malloc(sizeof(node));
	n->left=n->right=NULL;
	n->val=val;

	return n;
}
node *lca(node *root, int a, int b)
{
	if(root==NULL)
	{
		return NULL;
	}

	if(root->val>a && root->val>b)
	{
		return lca(root->left,a,b);
	}
	if(root->val<a && root->val<b)
	{
		return lca(root->right,a,b);
	}

	return root;
}
int main(int argc, char const *argv[])
{
	/* code */
	node *root=newNode(20);
	root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 	
 	printf("for 12 and 14 :%d\n",lca(root,12,14)->val);
	return 0;
}