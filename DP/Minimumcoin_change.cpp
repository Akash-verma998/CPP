#include<iostream>
using namespace std;
int minCoins(int n, int coins[], int T, int dp[])
{
    if(n==0)
        return 0;
    //look_up
    if (dp[n]!=0)
        return dp[n];
    //Recursive case
    int ans = INT_MAX;
    for(int i=0;i<T;i++)
    {
        if((n-coins[i])>=0)
        {
            int subproblem = minCoins(n-coins[i],coins,T,dp);
            ans = min(ans,subproblem+1);
        }
    }
    dp[n]=ans;
    return dp[n];

}
//coin change
int minCoinsBU(int N, int coins[],int T)
{
    int dp[50]={0};
    for(int n=1;n<=N;n++)
    {
        dp[n] = INT_MAX;
        for(int t=0;t<T;t++)
        {
            if(n-coins[t]>=0)
            {
                int sub = dp[n-coins[t]];
                dp[n]=min(dp[n],sub+1);
            }
        }

    }
    return dp[N];
}
int main()
{
    int n=15;
    int coins[] = {1,7,10};
    int dp[50]={0};
    int T=3;
    cout<<minCoins(n,coins,T,dp)<<endl;
    cout<<minCoinsBU(n,coins,T);
    return 0;
}

