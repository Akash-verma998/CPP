#include<iostream>
using namespace std;
int main()
{
    int arr[]={6,7,8,1,2,3,4,5};
    int n=8;
    int s=0, e=n-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(mid<e&&arr[mid]>arr[mid+1])
        {
            cout<<mid<<endl;
            break;
        }
        if(mid>s&&arr[mid]<arr[mid-1])
        {
            cout<<mid-1<<endl;
            break;
        }
        if(arr[s]>arr[mid])
        {
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
}
