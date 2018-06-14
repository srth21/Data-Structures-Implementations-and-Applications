/*
Input: pre[] = {20, 10, 11, 13, 12}
Output: Yes
The give array represents following BST. In the following BST, every internal
node has exactly 1 child. Therefor, the output is true.
        20
       /
      10
       \
        11
          \
           13
           /
         12

If each internal node has only one child, then all its descendants will either be greater than the node or all of them
will be smaller than the node.

we can use this concept and use two loops and check. This will be O(n^2)

Approach 2 : (Implemented Here)

Since all the descendants in preorder will be less than or greater than the node itself.
Find next descendant and last descendant : both must be greater or smaller
*/

#include<stdio.h>
#include<stdlib.h>


int check(int *arr, int n)
{
	int last=arr[n-1];

	for(int i=0;i<n-1;i++)
	{
		int next=arr[i+1];
		if((next-arr[i])*(last-arr[i])<0)
		{
			return 0;
		}
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	/* code */
	int pre[] = {8, 3, 5, 7, 6};
	int n=5;

	if(check(pre,n))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}