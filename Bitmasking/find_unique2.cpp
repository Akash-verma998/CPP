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
    cout<<firstno<<endl;
    cout<<seconno<<endl;

}
int main()
{
    int a[]={1,2,3,3,2,1,5,6};
    int n=sizeof(a)/sizeof(int);
    findunique2(a,n);
    return 0;
}
//incredible hulk
// lucky number

