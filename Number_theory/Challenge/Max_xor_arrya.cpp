#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	ll arr[n];
	ll xor_sum;
	xor_sum = 0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		xor_sum = xor_sum^arr[i];
	}
	ll ans=-9999;
	for(int i=0;i<n;i++)
	{
		ll st = xor_sum^arr[i];
		ans = max(ans,st);
	}
	cout<<ans<<endl;
	return 0;
}
