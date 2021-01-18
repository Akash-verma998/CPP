#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int binary_search1(int arr[],int s,int e,int key)
{
    if(s>e)
    {
        return -1;
    }
    int mid=(s+e)/2;
    if(arr[mid]==key)
        return mid;
    if(arr[s]<=arr[mid])
    {
        if(key>arr[s]&& key<=arr[mid])
            return binary_search1(arr,s,mid-1,key);
        else
            return binary_search1(arr,mid+1,e,key);
    }
    if(key>arr[mid]&&key<arr[e])
    {
        return binary_search1(arr,mid+1,e,key);
    }
    return binary_search1(arr,s,mid-1,key);
}

int main()
{
    int arr[]={6,7,8,1,2,3,4,5};
    int n=8;
    int key;
    cin>>key;
    int p = binary_search1(arr,0,n-1,key);
    cout<<p<<endl;
    return 0;
}
