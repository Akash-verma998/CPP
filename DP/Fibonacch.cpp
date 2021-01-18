#include<iostream>
using namespace std;
int fib(int n, int dp[])
{
    //base case
    if(n==0||n==1)
    {
        return n;
    }
    //recursive
    //look up
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans;
    ans = fib(n-1,dp)+fib(n-2,dp);
    return dp[n]= ans;
}
int fib2(int n, int dp[])
{
    for(int i=2;i<=n;i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fib3(int n)
{
    if(n==0||n==1)
        return n;
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int dp[50]={0};
    dp[0]=0;
    dp[1]=1;
    cout<<fib(n,dp);
    return 0;
}
