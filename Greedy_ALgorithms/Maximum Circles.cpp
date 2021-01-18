#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b)
{
	return (a.first+a.second)<(b.first<b.second);
}
int main()
{
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		int c,r;
		cin>>c>>r;
		v.push_back(make_pair(c,r));
	}
	sort(v.begin(),v.end(),comp);
	int count=1;
	int end = v[0].first+v[0].second;
	for(int i=1;i<n;i++)
	{
		int start = v[i].first-v[i].second;
		cout<<end<<start<<endl;
		if(end<=start)
		{
			count++;
			end = v[i].first+v[i].second;
		}
	}
	cout<<n-count<<endl;
}
