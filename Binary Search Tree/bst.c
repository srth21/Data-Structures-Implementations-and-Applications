#include<stdio.h>
#include<stdlib.h>

/*

The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree. 
In worst case, we may have to travel from root to the deepest leaf node. 
The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n).
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

int delete(Node **root, int key)
{
	Node *curr, *prev, *q, *inSuccessor;

	curr=*root;
	prev=NULL;

	while((curr!=NULL) && (curr->val!=key))
	{
		prev=curr;
		if(key<curr->val)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	if(curr==NULL)
	{
		printf("Node Not Found\n");
		return -1;
	}

	if(curr->left==NULL)
	{
		q=curr->right;
	}
	else if(curr->right==NULL)
	{
		q=curr->left;
	}
	else
	{
		inSuccessor=curr->right;
		while(inSuccessor->left!=NULL)
		{
			inSuccessor=inSuccessor->left;
		}

		inSuccessor->left=curr->left;
		q=curr->right;
	}

	if(prev==NULL)
	{
		//deleting the root
		*root=q;
	}
	else if(prev->left==curr)
	{
		prev->left=q;
	}
	else
	{
		prev->right=q;
	}
	return 1;
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}
int  search(int key, Node **root)
{
	Node *temp;
	temp=*root;

	while(temp!=NULL && temp->val!=key)
	{
		if(temp->val>key)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		return -1;
	}
	return 1;
}

int main()
{
	Node *root;

	root=(Node *)malloc(sizeof(Node));
	root=NULL;

	int x=insert(10,&root);
	x=insert(9,&root);
	x=insert(12,&root);
	x=insert(7,&root);
	x=insert(11,&root);
	x=insert(14,&root);
	preorder(root);
	x=delete(&root,12);
	printf("after deletion of 12\n");
	preorder(root);
	
	int temp=search(11,&root);
	if(temp==-1)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Found val. \n");
	}
	temp=search(21,&root);
	if(temp==-1)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Found val\n");
	}
	return 0;

}