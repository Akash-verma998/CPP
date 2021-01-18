
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a;
int* ps = new int[90000005];
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
    ll n;
    cin>>n;
    prime_sieve(90000000);
    for(ll i=0;i<=90000000;i++)
    {
        if(ps[i]==1)
        {
            a.push_back(i);
        }
    }
    cout<<a[n-1]<<endl;
    delete ps;
    return 0;
}
