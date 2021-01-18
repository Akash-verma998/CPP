#include<iostream>
#include<algorithm>
using namespace std;


 bool isToBeRemoved(int n)
 {
     if(n<=20)
     {
         return true;
     }
     else
     {
         false;
     }

 }
int main()
{
    int arr[10];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // remove all the element smaller than 20
    remove_if(arr,arr+n,isToBeRemoved);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
