/*
The square of prime number is  T-prime number
that have total 3 factors


*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a;
ll ps[1000005]={0};
void prime_sieve(ll n)
{
    //special case
    ps[0]=ps[1]=0;
    ps[2]=1;
    // removing all even number
    for(ll i=3;i<=n;i+=2)
    {
        ps[i]=1;
    }
    for(ll i=3;i<=n;i++)
    {
        if(ps[i])
        {
            for(ll j=i*i;j<=n;j=j+i)
                ps[j]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    ll p;
    prime_sieve(1000000);
    for(ll i=0;i<=1000000;i++)
    {
        if(ps[i]==1)
        {
            a.push_back(i*i);
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>p;
        ll ans = binary_search(a.begin(),a.end(),p);
        if(ans!=*a.end())
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        p=0;
    }
    return 0;
}
