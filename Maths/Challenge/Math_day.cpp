#include<iostream>
using namespace std;
int power(int a, int b,int p)
{
    a=a%p;
    //base case
    if(b==0)
    {
        return 1;
    }
    //recursive case
    long long int smallres=power(a,b/2,p);
    smallres=(smallres*smallres)%p;
    if(b&1)
    {
        smallres=(smallres*a)%p;
    }
    return smallres;
}
int main()
{
    unsigned int t,a,n,p;
    cin>>t;
    while(t--)
    {
        cin>>a>>n>>p;
        int ans=a%p;
        for(int i=2;i<=n;i++)
        {
            ans = power(ans,i,p);
        }
        cout<<ans<<endl;
    }
}
