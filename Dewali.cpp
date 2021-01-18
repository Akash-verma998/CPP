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
int mod = 1000003;
int x, n;
int dp[105][3][105];
int f(int i, int prev, int cnt)
{
    //base case
    if(i==n)
    {
        if(cnt==x)
        {
           return 1;
        }
        return 0;
    }
    // top down dp
    if(dp[i][prev][cnt]!=-1)
    {
        return dp[i][prev][cnt];
    }
    int ans = 0;
    if(prev ==1)
    {
        ans = ans + f(i+1,1,cnt+1);
    }
    else
    {
        ans = ans+ f(i+1,1,cnt);
    }
    ans = ans %mod;
    ans = ans + f(i+1,0,cnt);
    ans%=mod;
    return dp[i][prev][cnt]=ans;


}

int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>x;
        cout<<(f(1,0,0) + f(1,1,0))%mod<<endl;
    }
}
