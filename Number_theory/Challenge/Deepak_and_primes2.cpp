#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ps[100005];

void prime_sieve(){
    for(ll i=0;i<=100000;i++)ps[i]=1;
    for(ll i=2;i*i<=100000;i++){
        if(ps[i]){
            for(ll j=i*i;j<=100000;j+=i)
            ps[j]=0;
        }
    }
}
void segmented_sieve(ll a, ll b)
{
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    for(long long i=2;i*i<=b;i++)
    {
        if(ps[i]){
            int j;
            if(a>i){
				if(a%i)	j=a-a%i+i;
				else j=a;
			}
            else j=i;
            for(;j<=b;j+=i){
                if(j!=i) pp[j-a]=0;
            }
        }
    }
    for(long long i=a;i<=b;i++)
    {
        if(pp[i-a] && i!=1)
            cout<<(i)<<"\n";
    }
    cout<<"\n";
}
int main()
{
    int t;
    cin>>t;
    prime_sieve();
    while(t--)
    {
        ll n1,n2;
        cin>>n1>>n2;
        segmented_sieve(n1,n2);
    }
    return 0;
}
