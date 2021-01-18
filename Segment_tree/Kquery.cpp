#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N];
struct segmenttree_of_vectors
{
	vector<int> st[N*4];
	void build(int start, int end, int node)
	{
		if(start==end)
		{
			st[node].push_back(a[start]);
			return ;
		}
		int mid = (start+end)/2;

		//left tree
		build(start, mid,2*node+1);

		//right tree
		build(mid+1,end,2*node+2);

		// begin, end of first vector
		// begin and end of second vector
		//main final vector
		merge(st[2*node+1].begin(),st[2*node+1].end(),st[2*node+2].begin(),st[2*node+2].end(),back_inserter(st[node]));
	}
	int query(int start, int end, int l, int r, int k,int node)
	{
		if(start>r|| end<l)
		{
			return 0;
		}
		if(start>=l && end<=r)
		{
			return st[node].size()-(upper_bound(st[node].begin(),st[node].end(),k)-st[node].begin());
		}
		int mid = (start+end)/2;
		int left = query(start,mid,l,r,k,2*node+1);
		int right = query(mid+1,end,l,r,k,2*node+2);
		return left+right;
	}
}tree;



int main()
{
	int i, j,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	tree.build(0,n-1,0);
	cin>>m;
	while(m--)
	{
		int k;
		cin>>i>>j>>k;
		int l=i^ans , r= j^ans;
		k=k^ans;
		l--,r--;
		ans = tree.query(0,n-1,l,r,k,0);
		cout<<ans<<endl;
	}
}
