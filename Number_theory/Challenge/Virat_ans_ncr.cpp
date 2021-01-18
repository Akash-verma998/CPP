#include<iostream>
using namespace std;
#define ll long long
ll mod=1000000007;
ll fastexpomodulo(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1){
            res = (res*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return res;
}
ll fact(ll n)
{
	ll fact=1;
	for(ll i=1;i<=n;i++)
	{
		fact=(i*fact)%mod;
	}
	return fact;
}
int main()
{
	int n,r;
	cin>>n>>r;
	ll ans1 = fact(n);
	ll ans2 = fact(r);
	ll ans3 = fact(n-r);
	ans2  = fastexpomodulo(ans2,mod-2);
	ans3 = fastexpomodulo(ans3,mod-2);
	ll res  = (ans1%mod*ans2%mod*ans3%mod)%mod;
	cout<<res<<endl;
}
