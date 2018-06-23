#include <iostream>
using namespace std;
/*
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

                                {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };

                        x=4, y=4, color=3 

                               {{1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 1, 1, 1, 1, 0, 0},
                     {1, 0, 0, 1, 1, 0, 1, 1}, 
                     {1, 3, 3, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 0, 1, 0},
                     {1, 1, 1, 3, 3, 3, 3, 0},
                     {1, 1, 1, 1, 1, 3, 1, 1},
                     {1, 1, 1, 1, 1, 3, 3, 1}, };


Note: Use zero based indexing.


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1<=T<=100
1<=M[][]<=100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4


*/
void change(int **arr, int x, int y, int k, int m, int n, int ini)
{
  arr[x][y]=k;
  if(x+1<m && arr[x+1][y]==ini)
  {
    change(arr,x+1,y,k,m,n,ini);
  }
  if(y+1<n && arr[x][y+1]==ini)
  {
    change(arr,x,y+1,k,m,n,ini);
  }
  if(x-1>=0 && arr[x-1][y]==ini)
  {
    change(arr,x-1,y,k,m,n,ini);
  }
  if(y-1>=0 && arr[x][y-1]==ini)
  {
    change(arr,x,y-1,k,m,n,ini);
  }
}

int main() 
{
  int t;
  cin>>t;
  while(t--)
  {
    int m,n;
    cin>>m>>n;

    int **arr = new int*[m];
    for(int i=0;i<m;i++)
    {
      arr[i]=new int[n];
    }
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>arr[i][j];
      }
    }
    int x,y,k;
    cin>>x>>y>>k;
    int initialColor=arr[x][y];
    change(arr,x,y,k,m,n,initialColor);
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<arr[i][j]<<" ";
      }
    }
    cout<<endl;
  }

  return 0;
  //std::cout << "Hello World!\n";
}