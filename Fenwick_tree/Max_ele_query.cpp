#include<iostream>
using namespace std;
int a[10000];
int Bit[10000]={0};
void update(int i, int val, int n)
{
    while(i<=n)
    {
        Bit[i]=max(Bit[i],val);
        i+=(i&(-i));
    }
}
int query(int i)
{
    int ans = 0;
    while(i>0)
    {
        ans=max(ans,Bit[i]);
        i-=(i&(-i));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    //build the BIT
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i],n);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int idx;
        cin>>idx;
        cout<<query(idx)<<endl;
    }
    return 0;
}
