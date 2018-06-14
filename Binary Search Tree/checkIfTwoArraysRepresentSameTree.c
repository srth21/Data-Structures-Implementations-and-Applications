/*
Given two arrays which represent a sequence of keys. Imagine we make a Binary Search Tree (BST) from each array. We need to tell whether two BSTs will be identical or not without actually constructing the tree.

Examples
For example, the input arrays are {2, 4, 3, 1} and {2, 1, 4, 3} will construct the same tree

 Let the input arrays be a[] and b[]

Example 1:
a[] = {2, 4, 1, 3} will construct following tree.
   2
 /  \
1    4
    /
   3
b[] = {2, 4, 3, 1} will also also construct the same tree.
   2
 /  \
1    4
    /
   3 
So the output is "True"

Example 2:
a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13}
b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13}

They both construct the same following BST, so output is "True"
            8
         /    \
       3       10
     /  \        \
    1     6       14
        /   \     /
       4     7   13  

Algo Used :

For each position element in the array, the next smallest and the next largest element must be the same
and they must satisfy the min-max constraints.

*/


#include<stdio.h>
#include<stdlib.h>

int check(int *a, int *b, int n, int i, int j, int min, int max)
{
	int x,y;

	/* find next element in the range for each array and store the index */
	for(x=i;x<n;x++)
	{
		if(a[x]>min && a[x]<max)
		{
			break;
		}
	}
	for(y=j;y<n;y++)
	{
		if(b[y]>min && b[y]<max)
		{
			break;
		}
	}

	//if both leaf return true
	if(x==n && y==n)
	{
		return 1;
	}


	//if one is a leaf and the other is not return false
	if((x==n)^(y==n))
	{
		return 0;
	}

	//if the elements are not the same, return false
	if(a[x]!=b[y])
	{
		return 0;
	}

	//check recursively for the remaining elements
	//one for left subtree
	//one for right subtree
	return check(a,b,n,x+1,y+1,min,a[x]) && check(a,b,n,x+1,y+1,a[x],max);
}
int main(int argc, char const *argv[])
{
	/* code */
	int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   	int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};

   	int n=9;

   	if(check(a,b,n,0,0,INT_MIN,INT_MAX))
   	{
   		printf("YES\n");
   	}
   	else
   	{
   		printf("NO\n");
   	}
	return 0;
}