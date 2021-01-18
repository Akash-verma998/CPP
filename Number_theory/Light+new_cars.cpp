/*
concept use in this problem:
(a*b)%m = ((a%m)*(b%m))%m
(a+m)%m = ((a%m)+(b%m))%m
same as for (a^n)%m = ((a*b)%m*(a*b)%m......)%m
fermat litle theorem:
(a^(p-1))%p=1  where  p is a prime number


A^B where A can be anything and B can be anything
A^(a(p-1)+b)%p =  (A^(p-1))%p*(A^b%p) = (A^b%p)
so b = B^(p-1)%p

fast explotation used

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll t;
    cin>>t;
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        ll x = stringtoint(a,mod);
        //cout<<x<<endl;
        ll y = stringtoint(b,mod-1);
        //cout<<y<<endl;
        ll ans = power(x,y,mod);
        cout<<ans<<endl;
    }
    return 0;
}
