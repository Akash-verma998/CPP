
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
int r,s,p;
float dp[105][105][105];
void set_dp()
{
    for(int i=0;i<102;i++)
    {
        for(int j=0;j<102;j++)
        {
            for(int k=0;k<102;k++)
            {
                dp[i][j][k]=-1.0;
            }
        }
    }
}
float f1(int r, int s, int p)
{
    if(r==0 || s==0)
    {
        return 0.0;
    }
    if(p == 0)
    {
        return 1.0;
    }
    if(dp[r][s][p] !=-1.0)
    {
        return dp[r][s][p];
    }
    float tot = r*s + r*p + s*p;

    float ret=0.0;

    ret+=f1(r-1,s,p)*((r*p)/tot); //paper kills rock
    ret+=f1(r,s-1,p)*((r*s)/tot); //rock kills scissor
    ret+=f1(r,s,p-1)*((s*p)/tot); //scissor kills paper
    return dp[r][s][p] = ret;
}
float f2(int r, int s, int p)
{
    if(p==0 || s==0)
    {
        return 0.0;
    }
    if(r == 0)
    {
        return 1.0;
    }
    if(dp[r][s][p] !=-1.0)
    {
        return dp[r][s][p];
    }
    float tot = r*s + r*p + s*p;

    float ret=0.0;

    ret+=f2(r-1,s,p)*((r*p)/tot); //paper kills rock
    ret+=f2(r,s-1,p)*((r*s)/tot); //rock kills scissor
    ret+=f2(r,s,p-1)*((s*p)/tot); //scissor kills paper
    return dp[r][s][p] = ret;
}
float f3(int r, int s, int p)
{
    if(r==0 || p==0)
    {
        return 0.0;
    }
    if(s == 0)
    {
        return 1.0;
    }
    if(dp[r][s][p] !=-1.0)
    {
        return dp[r][s][p];
    }
    float tot = r*s + r*p + s*p;

    float ret=0.0;

    ret+=f3(r-1,s,p)*((r*p)/tot); //paper kills rock
    ret+=f3(r,s-1,p)*((r*s)/tot); //rock kills scissor
    ret+=f3(r,s,p-1)*((s*p)/tot); //scissor kills paper
    return dp[r][s][p] = ret;
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
        int r,s,p;
        cin>>r>>s>>p;
        set_dp();
        double ans1 = f1(r,s,p);
        set_dp();
        double ans2 = f2(r,s,p);
        set_dp();
        double ans3 = f3(r,s,p);
        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    }
}
