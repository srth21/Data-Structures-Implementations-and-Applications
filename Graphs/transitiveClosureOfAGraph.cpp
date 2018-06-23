#include <iostream>
using namespace std;

/*
Given a directed graph, find out if a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. 
Here reachable mean that there is a path from vertex i to j. 
The reach-ability matrix is called transitive closure of a graph.

Input:
First line consists of T test cases. First line of every test case consists of N , denoting number of vertices. 
Second line consists of N*N spaced integer(Only 0 and 1), denoting the edge b/w i to j.

Output:
Single line output, print the trasitive closure formed of graph.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
4
1 1 0 1 0 1 1 0 0 0 1 1 0 0 0 1
Output:
1 1 1 1 0 1 1 1 0 0 1 1 0 0 0 1



*/
void printTC(int **arr, int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    arr[i][j]=1;
                }
                arr[i][j]=arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==n-1 && j==n-1){
                cout<<arr[i][j];
            }
            else{
                cout<<arr[i][j]<<" ";    
            }
            
        }
    }
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int **arr=new int*[n];
	    for(int i=0;i<n;i++){
	        arr[i]=new int[n];
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    printTC(arr,n);
	    delete arr;
	    
	}
	
	return 0;
}