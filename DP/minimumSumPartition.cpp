/*

Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11


*/
#include<cmath>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int find(int *arr, int n, int j, int i, int sum, int**diff)
{
    int min=INT_MAX;
    for(int x=0;x<n;x++)
    {
        if(x!=j)
        {
            int s=diff[i-1][x];
            int a=(s+sum)/2;
            int b=sum-a;
           //cout<<"a :"<<a<<" b: "<<b<<" a-b "<<a-b<<endl;
            a-=arr[j];
            b+=arr[j];
            int d=abs(a-b);
            //cout<<"d "<<d<<endl;
            if(d<min)
            {
                min=d;
            }
        }
    }
    return min;
}
int check(int *arr, int n)
{
    int **diff;
    int half=n/2;
    diff=new int*[half];
    for(int i=0;i<half;i++)
    {
        diff[i]=new int[n];
    }
    int sum=0;
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        diff[0][i]=abs(sum-2*arr[i]);
       // cout<<"array of 0 "<<i<<" is "<<diff[0][i]<<endl;
        if(diff[0][i]<min)
        {
          min=diff[0][i];
        }
    }
    for(int i=1;i<half;i++)
    {
        for(int j=0;j<n;j++)
        {
            int f=find(arr,n,j,i,sum,diff);
            diff[i][j]=f;
           // cout<<"array of "<<i<<" "<<j<<" is "<<diff[i][j]<<endl;
            if(f<min)
            {
                min=f;
            }
        }
    }
    delete diff;
    return min;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int *arr;
	    arr=new int[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<check(arr,n)<<endl;
	}
	return 0;
}