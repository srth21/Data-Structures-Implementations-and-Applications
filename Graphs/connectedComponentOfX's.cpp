/*


Given N * M string array of O's and X's
Return the number of 'X' total shapes. 'X' shape consists of one or more adjacent X's (diagonals not included).

Example (1):

OOOXOOO
OXXXXXO
OXOOOXO

answer is 1 , shapes are  :
(i)     X
    X X X X
    X     X
 

Example (2):

XXX
OOO
XXX

answer is 2, shapes are
(i)  XXX

(ii) XXX

Input:
The first line of input takes the number of test cases, T.
Then T test cases follow. Each of the T test cases takes 2 input lines.
The first line of each test case have two integers N and M.The second line of N space separated strings follow which indicate the elements in the array.

Output:

Print number of shapes.

Constraints:

1<=T<=100

1<=N,M<=50

Example:

Input:
2
4 7
OOOOXXO OXOXOOX XXXXOXO OXXXOOO
10 3
XXO OOX OXO OOO XOX XOX OXO XXO XXX OOO

Output:
4
6

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x;
    int y;
    node() {};
    node(int x, int y): x(x), y(y) {};
};

bool isInside(int x, int y, int N, int M)
{
	if (x >= 0 && x < N && y >= 0 && y < M)
		return true;
	return false;
}
void visit( int n, int m, char **arr,int i, int j, bool **visited)
{
    //visited[i][j]=true;
    
    queue <node> q;
    q.push(node(i,j));
    int dx[]={-1,1,-1,1};
    while(!q.empty())
    {
        node t=q.front();
        q.pop();
        visited[t.x][t.y]=true;
        //cout<<"visiting X at "<<t.x<<" "<<t.y<<endl;
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
            //cout<<"new x and y :"<<newX<<" and "<<newY<<endl;
            if(isInside(newX,newY,n,m) && !visited[newX][newY] && arr[newX][newY]=='X')
            { 
                //cout<<"adding : "<<newX<<" and "<<newY<<endl;
                q.push(node(newX,newY));
            }
        }
    }
}
int solve(int n, int m, char **arr)
{
    int res=0;
    bool **visited;
    visited=new bool*[n];
    for(int a=0;a<n;a++)
    {   
        visited[a]=new bool[m];
        for(int b=0;b<m;b++)
        {
            visited[a][b]=false;
        }
    }
    //cout<<"starting"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='X' && !visited[i][j])
            {
              // cout<<"starting with  X at : "<<i<<" "<<j<<endl;
                visit(n,m,arr,i,j,visited);
                res++;
            }
        }
    }
    delete visited;
    
    return res;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    char **arr;
	    arr =new char*[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i]=new char[m];
	        for(int j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	        }
      }
      /*
      for(int i=0;i<n;i++)
	    {
	        //arr[i]=new char[m];
	        for(int j=0;j<m;j++)
	        {
	            cout<<arr[i][j]<<" ";
	        }
          cout<<endl;
      }*/
      //cout<<"done reading"<<endl;
	    cout<<solve(n,m,arr)<<endl;
	    delete arr;
	}
	return 0;
}