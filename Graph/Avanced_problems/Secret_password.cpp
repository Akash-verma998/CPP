#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
void dfs(int i, vector<bool> &vis)
{
	if(vis[i])
	{
		return ;
	}
	vis[i]=1;
	for(int nb: adj[i])
	{
		dfs(nb,vis);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> idv[26];
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for(char ch : s)
		{
			idv[ch-'a'].push_back(i);
		}
	}
	adj.resize(n);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j+1<idv[i].size();j++)
		{
			adj[idv[i][j]].push_back(idv[i][j+1]);
			adj[idv[i][j+1]].push_back(idv[i][j]);
		}
	}
	int ans=0;
	vector<bool> vis(n,0);
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		{
			continue;
		}
		dfs(i,vis);
		ans++;
	}
	cout<<ans<<endl;
}
