#include<stdio.h>
#include<stdlib.h>

/*

Given an array of size n. The problem is to check whether the given array can represent the level order traversal of a 
Binary Search Tree or not.

Examples:

Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
Output : Yes
For the given arr[] the Binary Search Tree is:
         7        
       /    \       
      4     12      
     / \    /     
    3   6  8    
   /   /    \
  1   5     10

Input : arr[] = {11, 6, 13, 5, 12, 10}
Output : No
The given arr[] do not represent the level
order traversal of a BST.

*/
typedef struct node node;

int check(int *arr, int n)
{
	int *values;
	int *min;
	int *max;

	values=(int *)calloc(n,sizeof(int));
	min=(int *)calloc(n,sizeof(int));
	max=(int *)calloc(n,sizeof(int));

	int notDone=1;

	int j=0;
	int i=0;
	values[j]=arr[i++];
	min[j]=INT_MIN;
	max[j]=INT_MAX;
	
	j+=1;

	while(i!=n && notDone)
	{
		int frontVal=values[0];
		int frontMin=min[0];
		int frontMax=max[0];

		//printf("Current Value : %d, Current MIN : %d. Current MAX :%d\n",frontVal,frontMin,frontMax );
		
		//popping from the queue
		for(int k=0;k<j-1;k++)
		{
			values[k]=values[k+1];
			min[k]=min[k+1];
			max[k]=max[k+1];
		}	
		values[j-1]=0;
		min[j-1]=0;
		max[j-1]=0;
		j-=1;
		int in=1;
		//check if arr[i] can be left child
		if(i<n && (arr[i]<frontVal && arr[i]>frontMin))
		{
			//printf("%d can be left child of %d\n",arr[i],frontVal);
			//printf("Incrementing i : with value of %d\n",arr[i]);
			values[j]=arr[i++];
			min[j]=frontMin;
			max[j]=frontVal;
			in=0;
			j+=1;
		}

		//check if arr[i] can be right child
		if(i<n && (arr[i]>frontVal && arr[i]<frontMax))
		{
			//printf("%d can be right child of %d\n",arr[i],frontVal);
			//printf("Incrementing i : with value of %d\n",arr[i]);
			values[j]=arr[i++];
			min[j]=frontVal;
			max[j]=frontMax;
			in=0;
			j+=1;
		}
		if(in)
		{
			//printf("Exiting because of : %d\n",arr[i]);
			notDone=0;
		}
		
	}

	if(i==n)
	{
		return 1;
	}
	return 0;


}
int main(int argc, char const *argv[])
{
	/* code */
	//+ve case
	int arr[]={7,4,12,3,6,8,1,5,10};
	int n=9;

	//-ve case
	//int arr[]={11, 6, 13, 5, 12, 10};
	//int n=6;	

	if(check(arr,n))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}