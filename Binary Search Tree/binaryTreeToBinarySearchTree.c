#include<stdio.h>
#include<stdlib.h>

//sorting algo to sort an array in ascending order
void sort(int *arr, int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

struct node
{
	int val;
	struct node* left;
	struct node* right;
};

typedef struct node node;

node *newNode(int val)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));

	temp->val=val;
	temp->left=temp->right=NULL;

	return temp;
}

void storeInorder(node *root, int *arr, int *size)
{
	if(root==NULL)
	{
		return;
	}

	storeInorder(root->left,arr,size);
	arr[*size]=root->val;
	*size+=1;
	storeInorder(root->right,arr,size);
}
int count(node *root)
{
	if(root==NULL)
	{
		return 0;
	}

	return count(root->left)+count(root->right)+1;
}

void arrayToBST(int *arr, node *root, int *i)
{
	if(root==NULL)
	{
		return;
	}
	arrayToBST(arr,root->left,i);

	root->val=arr[*i];
	*i+=1;

	arrayToBST(arr,root->right,i);
}
void createBST(node *root)
{
	if(root==NULL)
	{
		return;
	}

	int n=count(root);
	int *arr;

	arr=(int *)malloc(sizeof(int)*n);
	int i=0;
	storeInorder(root,arr,&i);

	sort(arr,n);

	i=0;
	arrayToBST(arr,root,&i);

	free(arr);

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
	node *root=NULL;
	root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    createBST(root);
    inorder(root);
	return 0;
}