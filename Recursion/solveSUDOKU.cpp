#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findBox(int i, int j)
{
  int a=i/3;
  int b=j/3;
  return 3*a + b;
}
bool solve(int arr[9][9], bool rows[9][10], bool cols[9][10], bool boxes[9][10], int x, int y)
{
  if(y==9)
  {
    return true;
  }

  int nx,ny;
  if(x==8)
  {
    nx=0;
    ny=y+1;
  }
  else
  {
    nx=x+1;
    ny=y;
  }

  if(arr[x][y]!=0)
  {
    return solve(arr,rows,cols,boxes,nx,ny);
  }
  int box=findBox(x,y);
  for(int k=1;k<=9;k++)
  {
    if(!rows[x][k] && !cols[y][k] && !boxes[box][k])
    {
      arr[x][y]=k;
      rows[x][k]=true;
      cols[y][k]=true;
      boxes[box][k]=true;
      if(solve(arr,rows,cols,boxes,nx,ny))
      {
        return true;
      }
      arr[x][y]=0;
      rows[x][k]=false;
      cols[y][k]=false;
      boxes[box][k]=false;
    }
  }
  return false;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int arr[9][9];
	    bool rows[9][10];
      bool cols[9][10];
      bool boxes[9][10];
      for(int i=0;i<9;i++)
      {
        memset(rows[i],false,sizeof(rows[i]));
        memset(cols[i],false,sizeof(cols[i]));
        memset(boxes[i],false,sizeof(boxes[i]));
      }
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        {
	            cin>>arr[i][j];
              if(arr[i][j]!=0)
              {
                rows[i][arr[i][j]]=true;
                cols[j][arr[i][j]]=true;
                int k=findBox(i,j);
                boxes[k][arr[i][j]]=true;
              }
	        }
	    }
	    bool a=solve(arr,rows,cols,boxes,0,0);
      for(int i=0;i<9;i++)
      {
        for(int j=0;j<9;j++)
        {
          cout<<arr[i][j]<<" ";
        }
      }
      cout<<endl;
	}
	return 0;
}