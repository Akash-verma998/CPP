#include<iostream>
#include<cmath>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;
#define ll long long
// O(n)
bool is_prime1(ll n)
{
    if(n==1)
        return false;
    else if(n==2)
        return true;
    else{
        for(ll i=2;i<n;i++)
        {
            if(n%i==0)
                return false;
        }
    }
    return true;
}
// O(root(n))
bool is_prime2(ll n)
{
    if(n==1)
        return false;
    else if(n==2)
        return true;
    else{
        for(ll i=2;i*i<n;i++)
        {
            if(n%i==0)
                return false;
        }
    }
    return true;
}
int n_bit = 10000000;
bitset<10000005> b;
vector<int> bit_prime;
void bitset_sieve()
{
    //set all bits
    b.set();// 1,1,1,1,1,1
    b[0] = b[1] = 0;
    for(ll i=2;i<=n_bit;i++)
    {
        if(b[i])
        {
            bit_prime.push_back(i);
            for(ll j=i*i;j<=n_bit;j+=i)
            {
                b[j]=0;
            }
        }
    }
}
bool is_prime_large_number(ll No)
{
   if(No<=n_bit)
   {
       return b[No] == 1 ? true : false;
   }
   for(ll i=0; bit_prime[i]*(ll) bit_prime[i]<=No;i++)
   {
       if(No&bit_prime[i]==0)
       {
           return false;
       }
   }
   return true;
}
void prime_sieve(int *p)
{
    //special case
    p[0]=p[1]=0;
    p[2]=1;
    // removing all even number
    for(ll i=3;i<=100000;i+=2)
    {
        p[i]=1;
    }
    for(ll i=3;i<=100000;i+=2)
    {
        if(p[i])
        {
            for(ll j=i*i;j<=100000;j=j+i)
                p[j]=0;
        }
    }
}
/*
int segmented_sieve(ll a, ll b)
{
    prime_sieve(sqrt(b));
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(long long i=2;i*i<=b;i++)
    {
        for(long long j=a;j<=b;j++)
        {
            if(ps[i])
            {
                if(j==i){
                    continue;
                }
                if(j%i==0)
                {
                    pp[j-a]=0;
                }
            }
        }
    }
    int res=0;
    for(long long i=a;i<b;i++)
    {
        res+=pp[i-a];
    }
    return res;
}
*/
int main()
{
    bitset_sieve();
    if(is_prime_large_number(2147483647))
    {
        cout<<"Yes It is\n";
    }
    else
    {
        cout<<"No its not!";
    }
    return 0;
    /*
    ll n1,n2;
    cin>>n1>>n2;
    int ans = segmented_sieve(n1,n2);
    cout<<ans<<endl;
    int p[100005]={0};
    prime_sieve(p);
    int csum[100005]={0};
    for(int i=1;i<=100000;i++)
    {
        csum[i] = csum[i-1]+p[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        cout<<csum[b]-csum[a-1]<<endl;
    }
    //bool p = is_prime(n);
    //cout<<p<<endl;
    */
}
