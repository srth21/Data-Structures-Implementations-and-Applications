#include <iostream>
using namespace std;

/*

Given an adjacency matrix representation of an unweighted undirected graph, your task is to complete the function eulerianPath(), that returns true if there is a Eulerian Path in the graph.

Examples:

Input : [[0, 1, 0, 0, 1],
         [1, 0, 1, 1, 0],
         [0, 1, 0, 1, 0],
         [0, 1, 1, 0, 0],
         [1, 0, 0, 0, 0]]

Output : 5 -> 1 -> 2 -> 4 -> 3 -> 2

Input : [[0, 1, 0, 1, 1],
         [1, 0, 1, 0, 1],
         [0, 1, 0, 1, 1],
         [1, 1, 1, 0, 0],
         [1, 0, 1, 0, 0]]
Output : No Solution
Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows. The first line of each test case contains an integer N denoting the number of vertices in the graph. Then each of next N lines contains N-space separated boolean value (0, 1) denoting that there is an edge between i and j.

Output:
For each test case print on a new line, 1 if there contains a Euler path in the graph else print 0.


Constraints:
1<=T<=58
1<=N<=50
Note: The graph consists of a single component.

Example:
Input:
2
5
0 1 0 1 1
1 0 1 0 1
0 1 0 1 1
1 1 1 0 0
1 0 1 0 0
5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
Output:
0
1

*/
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int odd=0;
	    for(int i=0;i<n;i++)
	    {
	        int c=0;
	        for(int j=0;j<n;j++)
	        {
	            int x;
	            cin>>x;
	            if(x==1)
	            {
	                c+=1;
	            }
	        }
	        if(c%2==1)
	        {
	            odd++;
	        }
	    }
	    if(odd==0 || odd==2)
	    {
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}