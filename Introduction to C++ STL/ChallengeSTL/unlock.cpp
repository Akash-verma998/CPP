#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    int a[n];
    int index[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        index[a[i]]=i;
    }
    ll i=0;
    int mx=n;
    while(k)
    {
        if(a[i]!=mx)
        {
            int p=index[mx];
            index[a[i]]=p;
            swap(a[i],a[p]);
            k--;
        }
        mx--;
        i++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }



}
