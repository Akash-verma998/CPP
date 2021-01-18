#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
#define ll long long
vector<ll> prims;
bool checkprime(ll i)
{
    ll p;
    bool is_prime = true;
    for(p=2;p<=sqrt(i);p++)
    {
        if(i%p==0)
        {
            is_prime=false;
            break;
        }
    }
    return is_prime;
}
void allprims(ll n)
{
    bool is_prime;
    ll num=n;
    ll i;
    while (num!=1)
    {
        for(i=2;i<=num;i++)
        {
            if(num%i==0)
            {
                is_prime=checkprime(i);
                if (is_prime)
                {
                    prims.push_back(i);
                    break;
                }
            }

        }
        num=num/i;
    }
}
ll sumdigit(ll n)
{
    ll s=0,r;
    while(n!=0)
    {
        r=n%10;
        s+=r;
        n=n/10;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    allprims(n);
    ll sum_of_digit = sumdigit(n);
    ll sumprime=0;
    ll sumdit=0;
    for(ll i=0;i<prims.size();i++)
    {
        sumdit=sumdigit(prims[i]);
        sumprime+=sumdit;
    }
    if(sumprime==sum_of_digit)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
