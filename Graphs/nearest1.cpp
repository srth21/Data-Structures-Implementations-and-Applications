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

int find(int **arr, int n,int m, int i, int j)
{
    //cout<<"arr value : "<<arr[i][j]<<endl;
    if(arr[i][j]==1)
    {
        return 0;
    }
    queue<node> q;
    
    bool visited[n][m];
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<n;b++)
        {
            visited[a][b]=false;
        }
    }
    //cout<<"not the same"<<endl;
    int dx[]={-1,1,-1,1};
    visited[i][j]=true;
    
    q.push(node(i,j));
    //cout<<"done pushing node"<<endl;
    while(!q.empty())
    {
        //cout<<"in loop"<<endl;
        node t=q.front();
        //cout<<"values at front "<<t.x<<" and "<<t.y<<endl;
        q.pop();
        //cout<<"arr val :"<<arr[t.x][t.y]<<endl;  
        if(arr[t.x][t.y]==1)
        {   
            //cout<<t.x<<" and "<<t.y<<endl;
            return (abs(t.x-i)+abs(t.y-j));
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
            //cout<<"new x and y :"<<newX<<" and "<<newY<<endl;
            if(isInside(newX,newY,n,m) && !visited[newX][newY])
            { 
                //cout<<"adding : "<<newX<<" and "<<newY<<endl;
                q.push(node(newX,newY));
            }
        }
    }
}
void printDistMatrix(int **arr, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        { 
           // cout<<"calling for i,j : "<<i<<" "<<j<<"arr L : "<<arr[i][j]<<endl;
            cout<<find(arr,n,m,i,j)<<" ";
        }
    }
    cout<<endl;
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{

      //cout<<"starting case "<<endl;
	    int n,m;
	    cin>>n>>m;
	    //cout<<n<<" and "<<m<<endl;
	    
      int **arr;
	    arr=new int*[n];
	   
      for(int i=0;i<n;i++)
	    {
	        arr[i]=new int[m];
	        for(int j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
      //cout<<"calling distance matrix"<<endl;
	    printDistMatrix(arr,n,m);
	    delete arr;
      //cout<<"done with case"<<endl;
	}
	return 0;
}