#include <iostream>
using namespace std;

void printTC(int **arr, int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][k]+arr[k][j]<arr[i][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
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