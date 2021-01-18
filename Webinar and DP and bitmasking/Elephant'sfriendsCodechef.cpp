#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mod 1000000007
#define Debug false

int stoi(string &s)
{
    stringstream ss(s);
    int x;
    ss>>x;
    return x;
}
int ALL_Person;
int dp[1025][102];
vector<vector<int>> v;
//mask denote set of people who got the t-shirt
//tid the current t-shirt we are going to giev to some person who had t-shirt in almirah
ll calc(int mask, int tid)
{
    if(mask==ALL_Person)
        return 1;
    //ALL t-shirt exhausted
    if(tid==101)
        return 0;
    if(dp[mask][tid]!=-1)
    {
        return dp[mask][tid];
    }
    ll ans = 0;
    //current tis is not alloted ot anyone
    ans = calc(mask,tid+1);
    //allot the current t-shirt to someone who has that t-shirt in the
    for(int p:v[tid])
    {
        if((mask&(1<<p))==0)
        {
            ans+=calc(mask|(1<<p),tid+1);
        }
    }
    ans %=Mod;
    dp[mask][tid] = ans;
    return ans;
}
int main()
{
    v.reserve(110);
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;
        ALL_Person = (1<<n)-1;
        string s;
        for(int i=0;i<=100;i++)
        {
            v[i].clear();
        }
        cin.get();
        //created the reverse mapping for the input
        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            stringstream ss(s);
            string temp;
            while(ss>>temp)
            {
                v[stoi(temp)].push_back(i);
            }
        }
        for(int i=0;i<=100;i++)
        {
            sort(v[i].begin(),v[i].end());
            if(v[i].size()>0 && Debug)
            {
                cout<<"T-Shirt "<<i<<"->";
                for(auto j: v[i])
                {
                    cout<<j+1<<",";
                }
                cout<<endl;
            }
        }
        cout<<calc(0,1)<<endl;
    }
    return 0;
}
