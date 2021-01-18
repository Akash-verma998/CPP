#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//#define int long long
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
int n, m;
int mod = 1000003;
vi adj[200001];
int p[200001],l[200001],in[200001],out[200001];
int tmv=0;
void dfs(int nd=1, int pr=0,int lv=0)
{
    l[nd] = lv;
    p[nd] = pr;
    in[nd] = tmv++;
    for(auto nb: adj[nd])
    {
        if(nb!=pr)
        {
            dfs(nb,nd,lv+1);
        }
    }
    out[nd] = tmv++;
}
int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    while(m--)
    {
        int farth , dp = -1;
        int k;
        cin>>k;
        vi v(k);
        for(int i=0;i<k;i++)
        {
            cin>>v[i];
            if(l[v[i]]>dp)
            {
                dp = l[v[i]] , farth = v[i];
            }
            v[i] = p[v[i]];
        }
        string ans = "YES";
        for(int i=0;i<k;i++)
        {
            if(!v[i])
                continue;
            if(in[v[i]] > in[farth] || out[v[i]] < in[farth])
            {
                ans="NO";
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}



