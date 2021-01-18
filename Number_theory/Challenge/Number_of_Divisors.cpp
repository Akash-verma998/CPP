#include<iostream>
#include<vector>
#include<map>
#define ll long long
#define Mod 1000000007
using namespace std;
int ps[1000005]={0};
vector<int> primes;
map<int,int> ma;
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
            for(ll j=i*i;j<n;j=j+i)
                ps[j]=0;
        }
    }
}
int main()
{
    prime_sieve(1000000);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=2;j<=a[i];j++){
                if(a[i]%j==0){
                    int x=j;
                    if(ps[j]){
                        while(a[i]%x==0){
                            m[j]++;
                            x=x*j;
                        }
                    }

                }
            }
        }
        int ans=1;
        for(auto it : m){
            ans*=(it.second+1);
        }
        cout<<ans<<endl;
    }
    return 0;
}

