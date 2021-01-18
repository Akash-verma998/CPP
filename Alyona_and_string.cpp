
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define float double
#define pd push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(),c.end()
#define mini(a,b,c) min(min(a,b),c)
#define rfor(i,n) for(int i=n-1;i>=0;i--)
#define ffor(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr),cout.tie(nullptr);
#define vi vector<int>
#define vf vector<float>
#define vvi vector<vector<int>>
#define mi map<int,int>
#define vpi vector<pair<int,int>>
#define pi pair<int, int>
string s,t;
int n,m,k;
int dp[1005][1005][12][2];
int solve(int is, int it, int rem,int cont)
{
    // p1 p2 p3 p4 p5
    // if p3 has a length of 5
    // p3 = abcde
    // then if we are on b in p3 then the rem stays out to be 3
    // jump from e in p3 makes rem to 2
    if(is ==n or it==m)
    {
        return ((rem==0)?0:INT_MIN);

    }
    if(rem==0)
    {
        return 0;
    }
    if(dp[is][it][rem][cont]!=-1)
        return dp[is][it][rem][cont];
    int ret = INT_MIN;
    ret = max(ret,solve(is+1,it,rem-cont,0));
    ret = max(ret,solve(is,it+1,rem-cont,0));
    if(s[is] == t[it])
    {
        ret = max(ret,1+solve(is+1,it+1,rem,1));
        ret = max(ret,1+solve(is+1,it+1,rem-1,0));
    }
    return dp[is][it][rem][cont]=ret;

}
int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m>>k;
    cin>>s>>t;
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0,k,0);
    return 0;
}
