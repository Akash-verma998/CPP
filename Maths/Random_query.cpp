#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
#define ll long long
ll a[1000005]={0};
ll prevocc[1000005]={0};
ll ans[1000005]={0};
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(prevocc,0,sizeof(prevocc));
    memset(ans,0,sizeof(ans));
    ans[0]=0;
    double sum=0.0;
    for(ll i=1;i<=n;i++)
    {
        ans[i]=ans[i-1]+(i-prevocc[a[i]]);
        prevocc[a[i]]=i;
        sum+=ans[i];
    }
    double finalans=0;
    finalans = (2*(sum-n)+n)/(n*n*1.0);
    cout<<fixed<<setprecision(6)<<finalans<<endl;
}
