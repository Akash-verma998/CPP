#include<iostream>
using namespace std;
int findunique3(int *a,int n)
{
    int cnt[64]={0};
    for(int j=0;j<n;j++)
    {
        //extract bit of every number and then update it.
        int i=0;
        int no=a[j];
        while(no>0)
        {
            cnt[i]+=(no&1);
            i++;
            no=no>>1;
        }
    }
    // take mod of cnt array with 3
    int p=1;
    int ans =0;
    for(int i=0;i<64;i++)
    {
        cnt[i]%=3;
        ans+=cnt[i]*p;
        p=p<<1;
    }
    return ans;

}
int main()
{
    int n;
    int a[100005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p=findunique3(a,n);
    cout<<p;
}
