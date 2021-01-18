#include<bits/stdc++.h>
using namespace std;
set<vector<int>> s;
void permute(vector<int> a,int i,int n)
{
	if(i==n)
	{
		s.insert(a);
		return ;
	}
	//recursive case
	for(int j=i;j!=n;j++)
	{
		swap(a[i],a[j]);
		permute(a,i+1,n);
		swap(a[i],a[j]);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int p;
		cin>>p;
		a.push_back(p);
	}
	permute(a,0,n);
	for(auto str: s)
	{
		for(auto ele: str)
			cout<<ele<<" ";
		cout<<"\n";
	}
	return 0;
}
