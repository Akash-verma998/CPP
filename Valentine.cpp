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
int m, n;
int d[5005][5005];
int a[5005],b[5005];
int f(int i, int j)
{
    if(i==n)
    {
        // we have pared aal the boys
        return 0;
    }
    if(j==m)
    {
        // we have rejected lot of girl ans not girl in avbl for the boys
        return INT_MAX;
    }
    if(d[i][j]!=-1)
    {
        return d[i][j];
    }
    int op1 = abs(a[i]-b[j]) +f (i+1,j);// by accepting the j the girl
    int op2 = f(i,j+1);// by rejectin the jth girl
    return d[i][j] = min(op1,op2);

}
int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    memset(d,-1,sizeof(d));
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int ans = f(0,0);
    cout<<ans<<endl;
    return 0;
}
