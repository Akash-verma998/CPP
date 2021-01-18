#include<iostream>
using namespace std;
int binary_search1(int arr[],int n,int key)
{
    int s=0;int e=n-1;
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8};
    int n=8;
    int key;
    cin>>key;
    int p = binary_search1(arr,n,key);
    cout<<p<<endl;
    return 0;
}
