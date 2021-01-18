#include<iostream>
using namespace std;
long long power(int a,int b)
{
    long long ans=1;
    while(b>0)
    {
        if((b&1)>0)
            ans=ans*a;
        a=a*a;
        b=b>>1;
    }
    ans=ans%1000000007;
    return ans;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,n;
        cin>>a>>n;
        long long p = power(a,n);
        cout<<p<<endl;
    }
    return 0;
}
