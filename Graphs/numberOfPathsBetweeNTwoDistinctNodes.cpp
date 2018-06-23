#include <iostream>
using namespace std;
void getAllPaths(int **arr, int a, int b, int n, bool *visited, int& pathCount, int l)
{
    visited[a]=true;
    if(a==b && l==0)
    {
        pathCount+=1;
    }
    else{
        if(a==b)
    {
        pathCount+=l;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(arr[a][i] && !visited[i])
            {
                int m=l;
                if(arr[a][i]>l)
                {
                    m=arr[a][i];
                }
                getAllPaths(arr,i,b,n,visited,pathCount,m);
            }
        }
    }
    visited[a]=false;
    }
    
}
void check(int **arr, int a, int b, int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int pathCount=0;
    getAllPaths(arr,a,b,n,visited,pathCount,0);
    
    cout<<pathCount<<endl;
}
int main() {
    //code
    int t;
    cin>>t;
    
    while(t--){
        int v,e;
        cin>>v>>e;
        
        int **arr = new int*[v];
        for(int i=0;i<v;i++)
        {
            arr[i]=new int[v]; 
        }
        for(int i=0;i<2*e;i+=2)
        {
            int a,b;
            cin>>a>>b;
            if(arr[a][b]>0)
            {
                arr[a][b]+=1;
            }
            else
            {
                arr[a][b]=1;
            }
                
        }
        
        //cout<<"inp done"<<endl;
        int a,b;
        cin>>a>>b;
        check(arr, a,b, v);
        
    }
	return 0;
}