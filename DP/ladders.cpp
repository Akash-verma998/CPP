#include<iostream>
using namespace std;
int ladders_top_down(int n, int k)
{
    if(n==0)
        return 1;
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=ladders_top_down(n-i,k);
        }
    }
    return ways;
}
// dp
int ladders_top_downDP(int n, int k,int dp[])
{
    if(n==0)
        return 1;
    int ways=0;
    if(dp[n]!=0)
        return dp[n];
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=ladders_top_down(n-i,k);
        }
        dp[n] = ways;
    }
    return dp[n]=ways;
}
//bottom up
int ladders_top_downBU(int n, int k)
{
    int dp[100]={0};
    dp[0] = 1;// Start case
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}
//Another optimized approach
int ladders_optimised(int n, int k)
{
    int dp[100]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=k;i++)
    {
       dp[i] = 2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    //print
    for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
}
int main()
{
    int n,k;
    int dp[100]={0};
    cin>>n>>k;
    cout<<ladders_top_down(n,k)<<endl;
    cout<<ladders_top_downDP(n,k,dp)<<endl;
    cout<<ladders_top_downBU(n,k)<<endl;
    cout<<ladders_optimised(n,k)<<endl;
    return 0;
}
