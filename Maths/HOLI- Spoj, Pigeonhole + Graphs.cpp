#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int>> edges;
vector<int> count;
vector<bool> visited;
vector<vector<int>> w;
void dfs(int v)
{
    visited[v]=true;
    for(int i=0;i<edges[v].size();i++)
    {
        int u = edges[v][i];
        if(visited[u])
            continue;
        dfs(u);
        count[v]+=count[u];
    }
    return;
}
long long sol(int v,int n)
{
    visited[v]=true;
    long long ans=0;
    for(int i=0;i<edges[v].size();i++)
    {
        int u = edges[v][i];
        if(visited[u])
            continue;
        ans += min(count[u],n - count[u]) * 2ll * w[v][i] + sol(u,n);
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    int Sn=1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            vector<int> v;
            edges.push_back(v);
            vector<int> v1;
            w.push_back(v1);
            count.push_back(1);
            visited.push_back(false);
        }
        for(int i=0;i<n-1;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            edges[x].push_back(y);
            edges[y].push_back(x);
            w[x].push_back(z);
            w[y].push_back(z);
        }
        dfs(1);
        for(int i=0;i<=n;i++)
            visited[i]=false;
        cout<<"Case #"<<Sn<<": "<<sol(1,n)<<endl;
        Sn++;
        for(int i = 0;i<=n;i++){
            edges[i].clear();
            w[i].clear();
            count[i] = 1;
            visited[i] = false;
        }
    }
    return 0;
}
