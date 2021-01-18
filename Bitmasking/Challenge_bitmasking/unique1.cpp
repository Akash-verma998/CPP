#include<iostream>
using namespace std;

int findunique(int *a,int n)
{
    int p=a[0];
    for(int i=1;i<n;i++)
    {
        p=p^a[i];
    }
    return p;
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
    int p=findunique(a,n);
    cout<<p;
}
