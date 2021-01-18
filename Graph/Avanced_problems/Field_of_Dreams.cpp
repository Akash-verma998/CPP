#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
map<pair<int,int>,int> cd;
string arr[401];
int cur=0,one=0,comp=0,n,m;
void add_edges()
{
	adj.resize(cur);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(arr[i][j]=='d')
			{
				continue;
			}
			int my = cd[{i,j}];
			if(i+1 < n && arr[i+1][j]=='g')
			{
				adj[my].push_back(cd[{i+1,j}]);
			}
			if(i && arr[i-1][j]=='g')
			{
				adj[my].push_back(cd[{i-1,j}]);
			}
			if(j && arr[i][j-1]=='g')
			{
				adj[my].push_back(cd[{i,j-1}]);
			}
			if(j+1 < m && arr[i][j+1]=='g')
			{
				adj[my].push_back(cd[{i,j+1}]);
			}
		}
	}
	n=cur;
}
vector<bool> visited;
vector<int> tin,low;
int timer;
void dfs(int v, int p=-1)
{
	visited[v]=true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for(int to:adj[v])
	{
		if(to==p)
		{
			continue;
		}
		if(visited[to])
			low[v] = min(low[v],tin[to]);
		else
		{
			dfs(to,v);
			low[v] = min(low[v],low[to]);
			if(low[to]>=tin[v] && p!=-1)
				one=1;
			++children;
		}
	}
	if(p==-1 && children > 1)
		one=1;
}
void find_cutpoints()
{
	timer =0;
	visited.assign(n,false);
	tin.assign(n,-1);
	low.assign(n,-1);
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			comp++;
			dfs(i);
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j]=='g')
			{
				cd[{i,j}] = (cur++);
			}

		}
	}
	add_edges();
	if(!n)
		cout<<0<<"\n";
	else if (n==1)
		cout<<1<<"\n";
	else if(n==2)
		if(adj[0].size())
			cout<<2<<"\n";
	    else
			cout<<0<<"\n";
	else
	{
		find_cutpoints();
		if(comp>1)
		{
			cout<<0<<"\n";
		}
		else if(one==1)
			cout<<1<<"\n";
		else
			cout<<2<<"\n";
	}
}
