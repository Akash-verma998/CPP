#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int ps[1000005]={0};
vector<int> primes;
vector<int> prime_sieve(ll n)
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
    for(ll i=0;i<n;i++)
    {
        if(ps[i]){
        primes.push_back(i);
        }
    }
    return primes;
}
// this returns a vector of prime factors;
vector<int> factorzation(int m)
{
    vector<int> factors;
    factors.clear();
    int i=0;
    int p=primes[0];
    while(p*p<=m)
    {
        if((m%p)==0){
            factors.push_back(p);
            while(m%p==0)
            {
                m=m/p;
            }
        }
        i++;
        p=primes[i];
    }

    //the last check of prime
    if(m!=1)
    {
        factors.push_back(m);
    }
    return factors;
}
int main()
{
    ll n;
    cin>>n;
    prime_sieve(n);
    for(auto no: primes){
        cout<<no<<" ";
    }
    cout<<"\n";
    ll m;
    cin>>m;
    vector<int> factors = factorzation(m);
    for(auto no: factors){
        cout<<no<<" ";
    }
}
