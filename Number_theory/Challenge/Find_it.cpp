#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> m;
int sum[100005]={0};
void solve()
{
	for(int i=2;i<=100000;i++)
	{
		for(int j=i;j<=100000;j+=i)
		{
			sum[i]+=m[j];
		}
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		v.push_back(p);
		m[v[i]]++;
	}
	solve();
	int q;
	cin>>q;
	sum[1] = n;
	for(int i=0;i<q;i++)
	{
		int k;
		cin>>k;
		cout<<sum[k]<<endl;
	}
	return 0;
}
