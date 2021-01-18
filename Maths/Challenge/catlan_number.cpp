#include<iostream>
using namespace std;
/*
Application of catlan number: count the number of bst with N nodes tree.
to check that question can be solved using catlan number just check that the anser for top n=5 answer
if answer is 1 1 2 5 14 42 132......

*/
#define ll unsigned long long
ll fact(ll x,ll y)
{
	ll f=1;
	if(x==y)return 1;
	if(y==0) return 1;
	if(y==1) return x;
    for(ll i=0;i<y;i++)
    {
        f=f*(x-i)/(i+1);
    }
    return f;
}

ll cal_prob(ll n,ll k)
{
    if(k>n/2)
    {
        k=n-k;
    }
   ll ans = fact(n,k);
   return ans;
}
int main()
{
    int n;
    cin>>n;
    unsigned long res=cal_prob(2*n,n);
    res = res/(n+1);
    cout<<res<<endl;
}
