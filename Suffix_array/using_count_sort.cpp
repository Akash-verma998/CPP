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
void radix_sort(vector<int> &p,vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n);
    for(auto x:c)
    {
        cnt[x]++;
    }
    vector<int> p_new(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++)
    {
        pos[i] = pos[i-1] + cnt[i-1];
    }
    for(auto x:p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p=p_new;
}
int32_t main()
{
    fast
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    s+="$";
    int n = s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i=0;i<n;i++)
        {
            a[i] = {s[i],i};
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {

            p[i] = a[i].second;
        }
        c[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(a[i].first == a[i-1].first)
            {
                c[p[i]] = c[p[i-1]];
            }
            else
            {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    int k=0;
    while((1<<k)<n)
    {
        for(int i=0;i<n;i++)
        {
            p[i] = (p[i] - (1<<k) + n)%n;
        }
        radix_sort(p,c);
        vector<int> c_new(n);
        c_new[p[0]] =0;
        for(int i=1;i<n;i++)
        {
            pair<int,int>prev = {c[p[i-1]],c[(p[i-1] + (1<<k))%n]};
            pair<int,int>now = {c[p[i]],c[(p[i] + (1<<k))%n]};
            if(now==prev)
            {
                c_new[p[i]] = c_new[p[i-1]];
            }
            else
            {
                c_new[p[i]] = c_new[p[i-1]] +1;
            }
        }
        c=c_new;
        k++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
