#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int main()
{
	int n,m;
	cin>>n>>m;
	adj.resize(n+1);
	while(m--)
	{
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> ans;
	set<int> can;
	vector<int> vis(n+1,0);

	ans.push_back(1);
	vis[1]=1;
	while(ans.size()<n)
	{
		int i=ans.back();
		for(int nb : adj[i])
		{
			if(!vis[nb])
				can.insert(nb);
		}
		auto it = can.begin();
		ans.push_back((*it));
		vis[(*it)]=1;
		can.erase(it);
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";

	}
	return 0;

}
