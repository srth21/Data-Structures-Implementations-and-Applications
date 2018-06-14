#include<stdio.h>
#include<stdlib.h>

/*

The worst case time complexity of search and insert operations is O(h) where h is height of Binary Search Tree. 
In worst case, we may have to travel from root to the deepest leaf node. 
The height of a skewed tree may become n and the time complexity of search and insert operation may become O(n).


Time Complexity of Kth Smallest Element is O(h) where h is the height of the tree

Algorithm:

in the structure to store the node, we store another variable called leftCount which stores the number of left children

if a node has k left children it is the k+1 smallest element in the tree

we start from the root and compare the value of k

if k==lc+1
	then we have found the element
if k< n+1
	we traverse to the left child and continue the search
if k>n+1
	we have to search in the right subtree for the k-lc-1 th smallest element
*/

struct node
{
	int val;
	int leftCount;
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
	temp->leftCount=0;

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
			curr->leftCount+=1;
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

int kthSmallestElement(Node *root, int k)
{
	int ret=-1;


	if(root)
	{
		Node *temp;
		temp=root;
		while(temp)
		{
			if(temp->leftCount)
			{
				ret=temp->val;
				break;
			}
			else if(k>temp->leftCount)
			{
				k=k-temp->leftCount-1;
				temp=temp->right;
			}	
			else
			{
				temp=temp->left;
			}
		}
		
	}

	return ret;
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
	
	printf("3rd Smallest Value is : %d\n",kthSmallestElement(root,3));
	return 0;

}