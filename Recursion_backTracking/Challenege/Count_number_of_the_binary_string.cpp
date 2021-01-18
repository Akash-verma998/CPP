#include<iostream>
using namespace std;
long long int binarystr(int n,long long int dp[])
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	if(dp[n]!=0)
		return dp[n];
	dp[n]= binarystr(n-1,dp)+binarystr(n-2,dp);
	return dp[n];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int dp[105]={0};
		long long int p = binarystr(n,dp);
		cout<<p<<endl;
	}
}
