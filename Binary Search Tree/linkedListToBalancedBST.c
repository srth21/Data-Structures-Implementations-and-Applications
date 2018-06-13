#include<stdio.h>
#include<stdlib.h>

struct list 
{
	int val;
	struct list* next;
};

typedef struct list list;


struct node
{
	int val;
	struct node *left;
	struct node *right;
};

typedef struct node node;

list *newListNode(int val)
{
	list *temp;
	temp=(list *)malloc(sizeof(list));

	temp->val=val;
	temp->next=NULL;

	return temp;
}

int findCenter(list *l)
{
	list *temp;
	temp=l;

	int count=0;

	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}

	if(count%2==1)
	{
		count=(count+1)/2;
	}
	else
	{
		count=count/2+1;
	}

	temp=l;
	int c=1;

	while(c!=count)
	{
		temp=temp->next;
		c++;
	}
	return temp->val;
}

list *findLeft(list *l, int val)
{
	list *first;
	first=l;
	list *temp;
	
	temp=newListNode(first->val);
	list *f;
	f=temp;

	while(first->val!=val)
	{
		temp->val=first->val;
		if(first->next->val==val)
		{
			temp->next=NULL;
		}
		else
		{
			temp->next=newListNode(-1);	
		}
		temp=temp->next;
		
		first=first->next;
	}
	temp=NULL;
	return f;
}

list *findRight(list * l, int val)
{
	list *temp;
	temp=l;

	while(temp->val!=val)
	{
		temp=temp->next;
	}
	return temp->next;
}

void printList(list *l)
{
	while(l!=NULL)
	{
		printf("%d\n",l->val);
		l=l->next;
	}
}
node *convertToTree(list *l)
{
	if(l==NULL)
	{
		return NULL;
	}

	node *root;
	root=(node *)malloc(sizeof(node));
	
	list *t;
	t=l;
	root->val=findCenter(l);
	
	//printf("For tree with root : %d\n",root->val);
	//printList(l);
	if(l->next==NULL)
	{
		//printf("child node\n");
		root->left=root->right=NULL;
		return root;
	}
	
	list *left;
	list *right;
	
	left=findLeft(t,root->val);
	
	//printf("leftval : %d\n",root->val );
	
	right=findRight(l,root->val);
	
	/*
	printf("left list\n");
	printList(left);
	printf("right list\n");
	printList(right);
	printf("end\n");
	*/
	
	root->left=convertToTree(left);
	root->right=convertToTree(right);

	return root;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	list *l;
	l=newListNode(10);
	l->next=newListNode(20);
	l->next->next=newListNode(30);
	l->next->next->next=newListNode(40);
	l->next->next->next->next=newListNode(50);
	l->next->next->next->next->next=newListNode(60);
	l->next->next->next->next->next->next=newListNode(70);

	node *root;
	root=(node *)malloc(sizeof(node));
	
	root=convertToTree(l);
	
	printf("Preorder Traversal of Created Tree.\n");
	preorder(root);
	return 0;
}