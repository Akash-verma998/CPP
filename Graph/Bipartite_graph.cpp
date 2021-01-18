/*
                       1         x-1
					  / \
					 2   3        x
					/ \ / \
				   6  7 4  5      x+1

we can put x-1 and x+1 element in same group

1st group = 1 6 7 4 5
2nd group = 2 3

                   1-------2
                   |       |
                   |       |
                   3-------4

1st group = 1 4
2nd group = 2 3
				   1-------2
				   |        \
				   |         5
                   |        /
                   3-------4

                   we can't break this into two part

if odd number of node is present and there is cycle then this is not bipartite.
cycle of odd length can't bipartite., bcz first and last or connected with a edge
*/


#include<bits/stdc++.h>
using namespace std;
const int N=100005 , M=22;
vector<int> gr[N];
int vis[N];
bool odd_cycle=0;
void dfs(int cur,int par,int col)
{
	vis[cur] = col;
	for(auto child: gr[cur])
	{
		if(vis[child]==0)
		{
			dfs(child,cur,3-col);
		}
		else if(child !=par && col==vis[child])
		{
			//bacakge and odd cycle
			odd_cycle=1;
		}
	}
	return ;
}
int main()
{
	int i,j,k,m,n,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1,0,1);
	if(odd_cycle)
	{
		cout<<"Not Bipartite\n";
	}
	else{
		cout<<"Bipartite\n";
	}
}
