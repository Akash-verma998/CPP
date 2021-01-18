/*
a*x=1(mod m)
here x is multiplicative modular inverse

fermat's little theorem
a^m = a(mod m)
a^m-1 = 1(mod' m)
a^m-2 = a^-1(mod m)
a^m-2 = 1/a(mod m)
a*a^m-2 = 1(mod m) // compare with ax=1 will get x = a^m-2

so a^m-2 is multiplicative modular inverse we can calculate using fast exponention

*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;
ll stringtoint(string a, ll m)
{
    ll ans=0;
    for(int i=0;i<a.size();i++)
    {
        ans+=(ans*10)%m + (a[i]-'0');
        ans%=m;
    }
    return ans;
}
ll power(ll x, ll y, ll m)
{
    if(y==0)
    {
        return 1;
    }
    ll smallpower = power(x,y/2,m);
    smallpower%=m;
    smallpower = (smallpower*smallpower)%m;
    if(y&1){
        smallpower = (smallpower*x)%m;

    }
    return smallpower;
}
int main()
{
    int n;
    cin>>n;
    ll ans = power(n,mod-2,mod);
    cout<<ans<<endl;
    return 0;
}
