
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
void radix_sort(vector<pair<pair<int,int>,int> > &a)
{
    int n = a.size();
    {
        vector<int> cnt(n);
        for(auto x:a)
        {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int,int>,int> > a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++)
        {
            pos[i] = pos[i-1] + cnt[i-1];
        }
        for(auto x:a)
        {
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a=a_new;
    }
    {
        vector<int> cnt(n);
        for(auto x:a)
        {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int,int>,int> > a_new(n);
        vector<int> pos(n);
        pos[0]=0;
        for(int i=1;i<n;i++)
        {
            pos[i] = pos[i-1] + cnt[i-1];
        }
        for(auto x:a)
        {
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a=a_new;
    }
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
        vector<pair<pair<int,int>,int> >a(n);
        for(int i=0;i<n;i++)
        {
            a[i] = {{c[i] , c[(i+(1<<k))%n]},i};
        }
        radix_sort(a);
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
                c[p[i]] = c[p[i-1]]+1;
            }
        }
        k++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
