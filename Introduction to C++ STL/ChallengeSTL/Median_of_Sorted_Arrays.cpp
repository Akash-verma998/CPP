#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a1[n],a2[n];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a2[i];
    }
    vector<int> v(2*n);
    merge(a1,a1+n,a2,a2+n,v.begin());
    vector<int>::iterator it;
    int a[2*n];
    int p=0;
    for(it=v.begin();it!=v.end();++it)
    {
        a[p++]=*it;
    }
    cout<<a[n-1];
    return 0;
}

