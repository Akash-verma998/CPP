#include<bits/stdc++.h>
using namespace std;
const int N=100005, M=22;
vector<int> gr[N];
void bfs(int src, int n, int &ans)
{
	vector<int> dis(n+1,INT_MAX);
	queue<int> q;
	q.push(src);
	dis[src]=0;
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(auto neigh:gr[cur])
		{
			if(dis[neigh]==INT_MAX)
			{
				dis[neigh] = dis[cur] +1;
				q.push(neigh);
				//neighbour not visited

			}
			else if(dis[neigh]>=dis[cur])
			{
				ans = min(ans,dis[neigh] + dis[cur]+1);
			}

		}
	}
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
		gr[y].push_back(x);
	}
	ans=n+1;
	for(i=1;i<=n;i++)
	{
		bfs(i,n,ans);
	}
	if(ans==n+1)
	{
		cout<<"No cycle\n";
	}
	else{
		cout<<"shortest cycle of length " <<ans<<"\n";
	}
}

