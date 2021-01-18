#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int arr[10000005]={0};
    long long int t,n;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        string name;
        long long int rank;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>name>>rank;
            arr[rank]++;
        }
        //greedy approach
        long long int actual_rank=1;
        long long int sum=0;
        for(int i=1;i<=n;i++)
        {
            while(arr[i])
            {
                sum+=abs(actual_rank-i);
                arr[i]--;
                actual_rank++;
            }

        }
        cout<<sum<<endl;
    }
}
