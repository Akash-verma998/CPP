/*
Articulation point and Bridge(logic and code)

DFS tree
Lowest Time
Discovered time
Back edge(Cycle)



see screen shot

Articulation point: vertex of a graph , if removing this vertex and all it's related edges, then number of the connected componnents increses
Bridge : Bridge is a edge if removing this edge , the number of connected components increases
Lowest time: minimum time of a node that a back edge is pointing.
5 5
1 2
2 3
3 1
3 4
4 5

*/


#include<bits/stdc++.h>
using namespace std;
const int N=100005, M=22;
int disc[N], low[N],tme;
vector<int> gr[N];
vector<int> art_p;
vector<pair<int,int>> bridge;
void dfs(int cur, int par)
{
	disc[cur] = low[cur] = tme++;
	int no_child = 0;
	for(auto child: gr[cur])
	{
		if(disc[child]==0)
		{
			dfs(child,cur);
			no_child++;
			low[cur] = min(low[cur],low[child]);
			if(par!=0 && low[child]>=disc[cur])
			{
				art_p.push_back(cur);
			}
			if(low[child]>disc[cur])
			{
				bridge.push_back({cur,child});
			}
		}
		else if(child !=par)
		{
			low[cur] = min(low[cur],disc[child]);
		}
	}
	//seprate case for root node
	if(par==0 && no_child>=2)
	{
		art_p.push_back(cur);
	}
	return;
}
int main()
{
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	tme=1;
	dfs(1,0);
	//for remove duplicate take set<int>
	for(auto x: art_p) cout<<x<<" ";
}
