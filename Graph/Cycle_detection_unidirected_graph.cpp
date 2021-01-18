/*
concept:  it two nodes in same components are being added then they from cycle.

*/
#include<bits/stdc++.h>
using namespace std;
const int N=100005, M=22;
struct dsu
{
	vector<int> p;
	void init(int n)
	{
		p.clear();
		p.resize(n);
		iota(p.begin(),p.end(),0);
	}
	int get(int x)
	{
		if(x==p[x])
			return x;
		else{
			// path compression
			return p[x] = get(p[x]);
		}
	}
	void unite(int x, int y)
	{
		x = get(x);
		y = get(y);
		if(x!=y)
		{
			p[x]=y;
		}
	}
}G;

int main()
{
	int i,j,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	G.init(n);
	bool cycle=0;
	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		if(G.get(x)!=G.get(y))
		{
			//different components
			G.unite(x,y);
		}
		else{
			//same compentes;
			//there was a pth x to y;
			cycle=1;
		}
	}
	if(cycle)
	{
		cout<<"Cycle in the Graph\n";
	}
	else{
		cout<<"No cycle\n";
	}
}
