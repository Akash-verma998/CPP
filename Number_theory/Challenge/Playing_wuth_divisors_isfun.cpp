#include<bits/stdc++.h>
using namespace std;
#define ll long long
//for concept check hakerearth
ll a[1000005];
ll m = 1000000007;
ll rev_two = m/2+1;
ll add(ll a, ll b) {
	a += b;
	if (a >= m) {
		a -= m;
	}
	return a;
}
ll mul(ll a, ll b) {
	return a * b % m;
}
int main()
{
    int n;
    cin>>n;
    ll prod = 1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        prod=(prod*(a[i]+1))%m;
    }
    ll ans = 1;
    for(int i=0;i<n;i++)
    {
        ll c = mul(a[i],prod);
        c = mul(c,rev_two);
        ans = mul(ans,add(c,1));
    }
    cout<<ans;
}
