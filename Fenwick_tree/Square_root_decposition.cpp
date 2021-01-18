#include<iostream>
#include<cmath>
using namespace std;
int query(int *blocks, int *arr, int l,int r, int rn)
{
    int ans=0;
    while(l<r && l!=0&&l%rn!=0)
    {
        ans+=arr[l];
        l++;
    }
    while(l+rn<=r)
    {
        int block_id = l/rn;
        ans+=blocks[block_id];
        l+=rn;
    }
    //right prt
    while(l<=r)
    {
        ans+=arr[l];
        l++;
    }
    return ans;

}
int main()
{
    int a[]={1,3,5,2,7,6,3,1,4,8};
    int n=sizeof(a)/sizeof(int);
    int rn=sqrt(n);
    //builds block query
    int block_id=-1;
    int *blocks = new int[rn+1]{0};
    for(int i=0;i<n;i++)
    {
        if(i%rn==0)
        {
            block_id++;
        }
        blocks[block_id]+=a[i];
    }
    //print blocks array
    for(int i=0;i<=rn;i++)
    {
        cout<<blocks[i]<<","<<endl;
    }
    cout<<query(blocks,a,2,8,rn);
    //updates query


}
