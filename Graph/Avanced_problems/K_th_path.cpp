#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long
#define float double
#define pb push_back
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
int inf=1e18;
int n, m;
void c_p_c()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int32_t main()
{
    c_p_c();
    int n,m,k;
    cin>>n>>m>>k;
    if(k<=m)
    {
        vector<pair<int,pi>> v;
        for(int id=0;id<m;id++)
        {
            int i,j,w;
            cin>>i>>j>>w;
            v.pb({w,{i,j}});
        }
        sort(v.begin(),v.end());
        if(k==1)
        {
            cout<<v[0].ff<<"\n";
            return 0;
        }
        mi s;
        for(int i=0;i<k-1;i++)
        {
            s[v[i].ss.ff] =1, s[v[i].ss.ss] =1;
        }
        int ls=0;
        for(auto &el:s)
        {
            el.ss = (++ls);
        }
        n=s.size();
        int d[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    d[i][j]=0;
                }
                else
                {
                    d[i][j]= inf;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(s.count(v[i].ss.ss) && s.count(v[i].ss.ff))
            {
                int u = s[v[i].ss.ss];
                int vl = s[v[i].ss.ff];
                d[u][vl] = d[vl][u] = v[i].ff;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    d[i][j] = min(d[i][j],d[i][k]+ d[k][j]);
                }
            }
        }
        vi vec;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                {
                    vec.pb(d[i][j]);
                }
            }
        }
        sort(vec.begin(),vec.end());
        cout<<min(vec[k-1],v[k-1].ff)<<"\n";
    }
    else
    {
        int d[n+1][n+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    d[i][j]=0;
                }
                else
                {
                    d[i][j]= inf;
                }
            }
        }
        while(m--)
        {
            int i,j,w;
            cin>>i>>j>>w;
            d[i][j] = d[j][i]=w;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    d[i][j] = min(d[i][j],d[i][k]+ d[k][j]);
                }
            }
        }
        vi v;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                {
                    v.pb(d[i][j]);
                }
            }
        }
        sort(v.begin(),v.end());
        cout<<v[k-1]<<"\n";
    }
    return 0;
}



