/*


Given a N X N matrix (M) filled with 1 , 0 , 2 , 3 . Your task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note : there is only single source and single destination.
 

Examples:

Input : M[3][3] = {{ 0 , 3 , 2 },
                   { 3 , 3 , 0 },
                   { 1 , 3 , 0 }};
Output : Yes

Input : M[4][4] = {{ 0 , 3 , 1 , 0 },
                   { 3 , 0 , 3 , 3 },
                   { 2 , 3 , 0 , 3 },
                   { 0 , 3 , 3 , 3 }};
Output : Yes


Input:
The first line of input is an integer T denoting the no of test cases. Then T test cases follow. Each test case consists of 2 lines . The first line of each test case contains an integer N denoting the size of the square matrix . Then in the next line are N*N space separated values of the matrix (M) .

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3 
3
0 3 2 3 0 0 1 0 0
Output:
1
0

*/


#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

struct node
{
    int x;
    int y;
    node(){}
    node(int x, int y): x(x), y(y) {}
};

bool isInside(int x, int y, int N, int M)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	return false;
}

int find(int **arr, int n,int m, int s1, int s2, int d1, int d2)
{
    queue<node> q;
    
    bool visited[n][m];
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            visited[a][b]=false;
        }
    }
    visited[s1][s2]=true;
    int dx[]={-1,1,-1,1};
    
    q.push(node(s1,s2));
  int i=0;
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        //cout<<"popping node with val "<<i<<endl;
        i+=1;
        if(arr[t.x][t.y]==2)
        {   
            return 1;
        }
        
        for(int v=0;v<4;v++)
        {
            int newX;
            int newY;
            if(v<2)
            {
              newX=t.x+dx[v];
              newY=t.y;
            }
            else
            {
               newX=t.x;
               newY=t.y+dx[v];
            }
            if(isInside(newX,newY,n,m) && !visited[newX][newY] && arr[newX][newY]!=0)
            { 
                //cout<<"adding : "<<newX<<" and "<<newY<<endl;
                visited[newX][newY]=1;
                q.push(node(newX,newY));
            }
        }
    }
    return 0;
}
void printDistMatrix(int **arr, int n, int m, int s1, int s2, int d1, int d2)
{
    cout<<find(arr,n,m,s1,s2,d1,d2)<<endl;    
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{

      int n,m;
	  cin>>n;
	  m=n;
      int **arr;
	  arr=new int*[n];
	  int s1, s2, d1, d2;
      for(int i=0;i<n;i++)
	    {
	        arr[i]=new int[m];
	        for(int j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	            if(arr[i][j]==1)
	            {
	                s1=i;
	                s2=j;
	            }
	            if(arr[i][j]==2)
	            {
	                d1=i;
	                d2=j;
	            }
	            
	        }
	    }
     //cout<<"finished reading"<<endl;
        printDistMatrix(arr,n,m,s1,s2,d1,d2);
	    delete arr;
        
	}
	return 0;
}