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
int mod = 1000003;
vector<pair<int,pi> >edge;
int parent[200001];
int size[200001];
map<int ,int> cntmap;

void c_p_c()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
void initialize()
{
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}
int root(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    return parent[x] = root(parent[parent[x]]);
}
int un(int u, int v)
{
    int ur=root(u);
    int vr=root(v);
    int rtval = size[ur] *  size[vr];
    parent[ur] = vr;
    size[vr] += size[ur];
    return rtval;
}
int32_t main()
{
    c_p_c();
    cin>>n>>m;
    for(int i=0;i<n-1;i++)
    {
        int u, v,w; cin>>u>>v>>w;
        edge.pb({w,{u,v}});
    }
    sort(edge.begin(),edge.end());
    initialize();
    for(int i=0;i<n-1;i++)
    {
        int u = edge[i].ss.ff , v=edge[i].ss.ss, w = edge[i].ff;
        cntmap[w] +=un(u,v);
    }
    int prev_val=0;
    vector<pi> v;
    for(auto &el : cntmap)
    {
        v.pb({el.ff,el.ss+prev_val});
        prev_val +=el.ss;
    }
    while(m--)
    {
        int qval;
        cin>>qval;
        pi tmp = {qval,inf};
        auto itval= upper_bound(v.begin(),v.end(),tmp);
        if(itval == v.begin())
        {
            cout<<0<<' ';
        }
        else
        {
            itval--;
            cout<< itval->ss<<' ';
        }
    }
    return 0;
}



