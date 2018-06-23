#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// structure for storing a cell's data
struct cell
{
	int x, y;
	int dis;
	cell() {}
	cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int N, int M)
{
	if (x >= 1 && x <= M && y >= 1 && y <= N)
		return true;
	return false;
}

// Method returns minimum step to reach target position
int find(int s1,int s2, int d1, int d2,int M,int N)
{
	// x and y direction, where a knight can move
	int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

	// queue for storing states of knight in board
	queue<cell> q;

	// push starting position of knight with 0 distance
	q.push(cell(s1, s2, 0));

	cell t;
	int x, y;
	bool visit[M + 1][N + 1];

	// make all cell unvisited
	for (int i = 1; i <=M; i++)
		for (int j = 1; j <= N; j++)
			visit[i][j] = false;

	// visit starting state
	visit[s1][s2] = true;

	// loop untill we have one element in queue
	while (!q.empty())
	{
		t = q.front();
		q.pop();

		// if current cell is equal to target cell,
		// return its distance
		if (t.x == d1 && t.y == d2)
			return t.dis;

		// loop for all reachable states
		for (int i = 0; i < 8; i++)
		{
			x = t.x + dx[i];
			y = t.y + dy[i];

			// If reachable state is not yet visited and
			// inside board, push that state into queue
			if (isInside(x, y, N,M) && !visit[x][y]) {
				visit[x][y] = true;
				q.push(cell(x, y, t.dis + 1));
			}
		}
	}
	return -1;
}
void check(int s1, int s2, int d1, int d2,int n, int m)
{
    int count=find(s1,s2,d1,d2,n,m);
    cout<<count<<endl;
    
}
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int m,n;
	    cin>>n>>m;
	    int s1,s2,d1,d2;
	    cin>>s1>>s2>>d1>>d2;
	    check(s1,s2,d1,d2,n,m);
	}
	return 0;
}