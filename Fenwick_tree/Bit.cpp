#include<iostream>
using namespace std;
int a[10000];
int Bit[10000]={0};
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
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
    return 0;
}
