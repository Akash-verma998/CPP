#include<iostream>
using namespace std;
int main()
{
    long long int n,i;
    long long int  arr[11111];
    while(1)
    {
        long long int max_load =0,load=0;
        cin>>n;
        //stop taking input if n==1
        if(n==-1)
            break;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            load+=arr[i];
        }
        //find the load that divide equally
        if(load%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        load=load/n;
        long long int diff=0;
        for(i=0;i<n;i++)
        {
            diff+=(arr[i]-load);
            long long int ans = max(diff,-diff);
            max_load = max(max_load,ans);

        }
        cout<<max_load<<endl;
    }
    return 0;
}
