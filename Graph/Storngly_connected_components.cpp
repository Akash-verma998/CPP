/*
in directed graph a set of nodes is called strongly connected components , if we can got to each other for any of the node.
strongly connected use in directed graph

And if a graph have only one strongly connected components then is it called strongly connected graph
kosaraju algorithm

6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4

time complexity:  O(n+n) = O(n)

*/

#include<bits/stdc++.h>
using namespace std;
const int N=100005, M=22;
vector<int> gr[N] ,grr[N];
vector<int> order;
int vis[N],comp[N];
void def_rev(int cur,int col)
{
	comp[cur] = col;
	vis[cur] = 1;
	for(auto x: gr[cur])
	{
		if(!vis[x])
			def_rev(x,col);
	}
}
void dfs(int cur)
{
	vis[cur] = 1;
	for(auto x: gr[cur])
	{
		if(!vis[x])
			dfs(x);
	}
	order.push_back(cur);
}
int main()
{
	int i,j,n,m,ans;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		int x, y;
		cin>>x>>y;
		gr[x].push_back(y);
		grr[y].push_back(x);
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}
	memset(vis,0,sizeof(vis));
	int col=1;
	for(i=n;i>=1;i--)
	{
		if(!vis[order[i]])
		{
			def_rev(order[i],col);
			col++;
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<i<<"-->"<<comp[i]<<"\n";
	}
}
