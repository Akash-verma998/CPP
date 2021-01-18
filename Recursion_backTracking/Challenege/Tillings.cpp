#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int m;
int foc(int n,int dp[])
{
	if(n<=m-1)
		return 1;
	if(dp[n]!=0)
		return dp[n];
	dp[n] = (foc(n-1,dp)%mod+foc(n-m,dp)%mod)%mod;
	return dp[n]%mod;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n>>m;
		int dp[100006]={0};
		int ans = foc(n,dp)%mod;
		cout<<ans<<endl;
	}
}
