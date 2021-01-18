#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<vector<int>> adj;
int n,m;
int mod =998244353;
int cnt0=0,cnt1=0,can=1;
int pwmd(int a, int n)
{
	if(!n)
	{
		return 1;
	}
	int pt = pwmd(a,n/2);
	pt = pt*pt;
	pt%=mod;
	if(n&1)
	{
		pt*=a;
		pt%=mod;
	}
	return pt;
}
void dfs(int i, vector<int> &vis, int parity=0)
{
	if(vis[i])
	{
		if(1+parity!=vis[i])
		{
			can=0;
		}
		return ;
	}
	if(parity==0)
	{
		cnt0++,vis[i]=1;
	}
	else
	{
		cnt1++,vis[i]=2;
	}
	for(auto el: adj[i])
	{
		dfs(el,vis,1-parity);
	}
}
int get()
{
	int ans=1;
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			cnt0=0,cnt1=0,can=1;
			dfs(i,vis,0);
			if(!can)
				return 0;
			ans =(ans*(pwmd(2,cnt0) + pwmd(2,cnt1)))%mod;
		}
	}
	return ans;
}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		adj.clear();
		adj.resize(n+1);
		while(m--)
		{
			int v,u;
			cin>>v>>u;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout<<get()<<endl;
	}
	return 0;
}
