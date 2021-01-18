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
int arr[501][501];
vector<pi> adj[501][501];
vector<pi> spl;
bool check(int a, int b)
{
    return (a>=1 && b >=1 && a<=n && b <=m);
}
int get_ans()
{
    queue<pi> q;
    vector<vector<bool>> vis(n+1, vector<bool>(m+1,0));
    vector<vi> d(n+1,vi(m+1));
    for(pi cell : spl)
    {
        d[cell.ff][cell.ss] = 0;
        vis[cell.ff][cell.ss] = 1;
        q.push(cell);

    }
    int ans=0;
    while(!q.empty())
    {
        pi v = q.front();
        q.pop();
        for(pi u: adj[v.ff][v.ss])
        {
            if(!vis[u.ff][u.ss])
            {
                vis[u.ff][u.ss] = true;
                q.push(u);
                d[u.ff][u.ss] = d[v.ff][v.ss] + 1;
                ans = max(ans, d[u.ff][u.ss]);
            }
        }
    }
    return ans;
}
void add_edges()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            adj[i][j].clear();
            int di[] = {-1,-1,-1,0,0,1,1,1};
            int dj[] = {-1,0,1,-1,1,-1,0,1};
            for(int id=0;id<8;id++)
            {
                if(check(i+di[id] , j+dj[id]))
                {
                    adj[i][j].push_back({i+di[id],j+dj[id]});
                }
            }
        }
    }
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
        cin>>n>>m;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>arr[i][j];
                mx = max(mx,arr[i][j]);
            }
        }
        add_edges();
        spl.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i][j]==mx)
                {
                    spl.push_back({i,j});
                }
            }
        }
        cout<<get_ans()<<"\n";
    }
    return 0;
}



