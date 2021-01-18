#include<iostream>
using namespace std;
#define ll long long
ll m=10000000;
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
int main()
{
    //a=a(a^b/2)^2 when b is odd
    //a=(a^b/2)^2 when b is even
    int a,b;
    cin>>a>>b;
    int p=fastexpomodulo(a,b,m);
    cout<<p;
}
