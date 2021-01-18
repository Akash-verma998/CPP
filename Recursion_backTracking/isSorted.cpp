#include<iostream>
using namespace std;
bool isSorted(int *a, int n)
{
    if(n==1)
    {
        return true;
    }
    if(a[0]<a[1]&& isSorted(a,n-1))
        return true;
    return false;
}
int main()
{
    int a[]={1,2,3,4,5};
    int n=5;
    if (isSorted(a,n))
    {
        cout<<"Yes Sorted\n";
    }
    else
    {
        cout<<"Not Sorted\n";
    }
    return 0;
}
