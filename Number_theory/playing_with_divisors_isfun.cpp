#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[1000005];
ll mod = 1000000007;
ll power(ll a, ll b, ll c) {
    ll res = 1;
    while (b) {
        if (b & 1)
			res = (res * a) % c;
        b >>= 1;
        a = (a *a) % c;
    }
    return res;
}
int main()
{
	int n;
	cin>>n;
	ll product = 1,product1,x,ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		product = (product*(a[i]+1))%mod;
	}
	for(int i=0;i<n;i++)
	{
		product1 = (product*power(a[i]+1,mod-2,mod))%mod;
		x=(a[i]*(a[i]+1))%mod;
		x = (x*power(2,mod-2,mod))%mod;
		ans = (ans*((product1*x+1)%mod))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
