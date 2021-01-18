#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[10000];
int Bit[100000]={0};
void update(int i, int inc, int n)
{
    while(i<=n)
    {
        Bit[i]+=inc;
        i+=(i&(-i));
    }
}
int query(int i)
{
    int ans = 0;
    while(i>0)
    {
        ans+=Bit[i];
        i-=(i&(-i));
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //build the BIT
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int ans=0;
        for(int i=n;i>=1;i--)
        {
            ans += query(a[i]-1);
            update(a[i],1,n);
        }
        memset(Bit,0,sizeof(Bit));
        cout<<ans<<endl;
    }
    return 0;
}

