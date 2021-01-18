#include<iostream>
#include<algorithm>
using namespace std;
void bubblesort(int a[],int n)
{
    if(n==1)
    {
        return ;
    }
    for(int i=0;i<=n-2;i++)
    {
        if(a[i]>a[i+1])
        {
            swap(a[i],a[i+1]);
        }
    }
    bubblesort(a,n-1);
}
void bubblesort2(int a[],int n,int j)
{
    if(n==1)
    {
        return;
    }
    if(j==n-1)
    {
        return bubblesort2(a,n-1,0);
    }
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    bubblesort2(a,n,j+1);
    return ;
}
int main()
{
    int a[]={1,3,2,5,4};
    int n=5;
    bubblesort2(a,n,0);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
