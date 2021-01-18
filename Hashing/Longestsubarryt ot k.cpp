
#include<iostream>
#include<unordered_map>
using namespace std;
int check(int *arr, int n,int k)
{
    unordered_map<int,int> mp;
    int pre=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        pre+=arr[i];
        if(arr[i]==0 and len==0) len=1;
        if(pre==k)len=max(len,i+1);
        if(mp.find(pre-k)!=mp.end())
        {
            len = max(len,i-mp[pre-k]);
        }
        else
        {
            mp[pre]=i;
        }
    }
    return len;

}
int main()
{
    int n,k;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    int b = check(arr,n,k);
    cout<<b<<endl;
}

