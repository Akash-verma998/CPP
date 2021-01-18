#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
    return a>b;
}
int main()
{
    int a[]={5,4,3,1,2,6,7};
    int n=sizeof(a)/sizeof(int);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    // sort in reverse order
    sort(a,a+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
