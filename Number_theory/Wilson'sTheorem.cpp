/*
/// Wilson's Theorem
n is a prime no
(n-1)! = -1(mod n)

// Boring factorial


*/
#include<iostream>
using namespace std;
#define ll long long
ll fastexpomodulo(ll a, ll b, ll m)
{
    ll res=1;
    while(b>0)
    {
        if(b&1){
            res = (res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}
ll solve(ll n ,ll p)
{
    ll ans=-1;
    for(ll i=(n+1);i<=(p-1);i++)
    {
        ll temp = fastexpomodulo(i,p-2,p);
        ans = (ans*temp)%p;
    }
    return (ans+p);
}
int main()
{
    ll t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        if(n>=p)
            cout<<"0"<<endl;
        else{
            cout<<solve(n,p)<<endl;
        }
    }
    return 0;
}
