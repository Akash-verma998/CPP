#include<iostream>
using namespace std;
int Bit[1000]={0};
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
        int n,u;
        cin>>n>>u;
        for(int i=0;i<u;i++)
        {
            int l,r,val;
            cin>>l>>r>>val;
            update(l,val,n);
            update(r+1,-val,n);
        }
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            int qe;
            cin>>qe;
            cout<<query(qe)<<endl;
        }
    }
}
