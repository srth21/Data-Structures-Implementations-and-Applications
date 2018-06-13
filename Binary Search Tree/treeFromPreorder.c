#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

typedef struct node node;

//make a node with value val.
node *createNewNode(int val)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp->val=val;
	temp->left=temp->right=NULL;

	return temp;
}

/*

preoorder is the array containing the elements in preorder traversal
preindex is the index of the current root
low and high depict the range of values in the subtree rooted at the current root

*/

node *constructTree(int *preorder, int *preIndex, int low, int high, int n)
{
	//base case : 
	//		current root overflow
	// 		range overflow
	if(*preIndex>=n || low>high)
	{
		return NULL;
	}

	//allocate current root
	node *root=createNewNode(preorder[*preIndex]);
	*preIndex=*preIndex+1;

	//only one element
	//leaf case
	if(low==high)
	{
		return root;
	}

	//search for first element greater than root
	int i;
	for(i=low;i<high;i++)
	{
		if(preorder[i]>root->val)
		{
			break;
		}
	}

	//recursively construct left and right subtree
	root->left=constructTree(preorder,preIndex,*preIndex,i-1,n);
	root->right=constructTree(preorder,preIndex,i,high,n);

	return root;
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->val);
		inorder(root->right);
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	int pre[]={10,5,1,7,40,50};
	int size=6;
	int preindex=0;
	node *root=constructTree(pre,&preindex,0,size-1,size);

	inorder(root);
	return 0;
}