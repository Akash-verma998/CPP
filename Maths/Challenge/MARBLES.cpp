#include<iostream>
using namespace std;
#define ll long long
ll fact(ll x,ll y)
{
	ll f=1;
	if(x==y)return 1;
	if(y==0) return 1;
	if(y==1) return x;
    for(ll i=0;i<y;i++)
    {
        f=f*(x-i)/(i+1);
    }
    return f;
}

ll cal_prob(ll n,ll k)
{
    if(k>n/2)
    {
        k=n-k;
    }
   ll ans = fact(n,k);
   return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll p = cal_prob(n-1,k-1);
        cout<<p<<endl;
    }
}
