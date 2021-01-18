#include<iostream>
using namespace std;
float binary_search1(int key,int pr)
{
    int s=0;int e=key;
    int mid;
    float ans=0.0;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(mid*mid==key)
        {
            ans=mid;
            break;
        }
        else if(mid*mid<key){
            s=mid+1;
            ans=mid;
        }
        else
        {
            e=mid-1;
        }
    }
    float inc=0.1;
    for(int i=0;i<pr;i++)
    {
        while(ans*ans<=key)
        {
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main()
{
    int key,pr;
    cin>>key>>pr;
    float p = binary_search1(key,pr);
    cout<<p<<endl;
    return 0;
}
