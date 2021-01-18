/*
we can find connected components using disjoint set
	  ___________
     |          |
1    2    3     4      5
|_________|

connected components : (1,3) (2,4) (5)

parent: 1 2 3 4 5
sets:   1 2 3 4 5

1 parent of 1, 2 parent 2, 3 parent 3, 4 parent 4.........

super parent concept:

super parent of 1 is 3, and super parent of 3 is 3
super parent of 2 is 4, and super parent of 4 is 4
super parent of 5 is 5

if the super parent of two nodes is same then both belong to same components.

time complexity: O(n^2)

that's why use path compression

*/
#include<bits/stdc++.h>
using namespace std;
const int N=100005, M=22;
struct dsu
{
	int total_comp;
	vector<int> par;
	vector<int> sz;
	void init(int n)
	{
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			sz[i]=1;
		}
		total_comp = n;
	}
	int get_super_parent(int x)
	{
		if(x==par[x])
			return x;
		else{
			// path compression
			return par[x] = get_super_parent(par[x]);
		}
	}
	void unite(int x, int y)
	{
		int super_parent_x = get_super_parent(x);
		int super_parent_y = get_super_parent(y);
		if(super_parent_x != super_parent_y)
		{
			par[super_parent_x] = super_parent_y;
			sz[super_parent_y] += sz[super_parent_x];
			sz[super_parent_x] = 0;
			total_comp--;
		}
	}
}G;
int main()
{
	int i,j,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	G.init(n);
	for(i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		G.unite(x,y);
	}
	//all element are in there connected components
	for(i=0;i<n;i++)
	{
		int super_parent_i = G.get_super_parent(i);
		ans+=(n-G.sz[super_parent_i]);
	}
	cout<<ans/2<<endl;
}
