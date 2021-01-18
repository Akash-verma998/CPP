#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1,2,34,56,12,3};
    int n = sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    auto it  = find(a,a+n,key);
    int index = it-a;
    if(index==n)
    {
        cout<<"Element is not present";
    }
    else
        cout<<"Present at index"<<index;
    return 0;
}
