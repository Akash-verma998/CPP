#include<iostream>
using namespace std;
void findunique2(int *a, int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        res = res^a[i];
    }
    int i=0;
    int temp=res;
    while(res)
    {
        if(temp&1)
        {
            break;
        }
        i++;
        temp=temp>>1;
    }
    int mask =(1<<i);
    int firstno=0;
    for(int i=0;i<n;i++)
    {
        if((mask&a[i])!=0)
        {
            firstno=firstno^a[i];
        }
    }
    int seconno=res^firstno;
    if (firstno<seconno)
    {
        cout<<firstno<<" "<<seconno;
    }
    else{
        cout<<seconno<<" "<<firstno;
    }
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
    findunique2(a,n);
}
