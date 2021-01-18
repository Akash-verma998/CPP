#include<iostream>
#include<algorithm>
using namespace std;
bool canplace(int stall[],int n,int c,int min_sep)
{
    int last_cow = stall[0];
    // place first in first stall
    int cnt =1;
    for(int i=0;i<n;i++)
    {
        if(stall[i]-last_cow>=min_sep)
        {
            last_cow = stall[i];
            cnt++;
            if(cnt==c)
                return true;
        }
    }
    return false;

}
int main()
{
    int n,cows;
    cin>>n>>cows;
    int stall[100005];
    for(int i=0;i<n;i++)
    {
        cin>>stall[i];
    }
    sort(stall,stall+n);
    int s=0;
    int e = stall[n-1]-stall[0];
    int ans =0;
    while(s<=e)
    {
        int mid=(s+e)/2;
        bool cowrkhpye = canplace(stall,n,cows,mid);
        if(cowrkhpye)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
