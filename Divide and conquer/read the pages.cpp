#include<iostream>
using namespace std;
#define ll long long int
bool isvalid(ll books[],ll n,ll k,ll ans)
{
    int student=1;
    ll current_pages=0;
    for(int i=0;i<n;i++)
    {
        if((current_pages+books[i])>ans)
        {
            current_pages=books[i];
            student++;
            if(student>k)
                return false;
        }
        else
        {
            current_pages+=books[i];
        }
    }
    return true;
}
ll binarysearch(ll books[],ll n,ll k)
{
    ll total_pages=0;
    ll s=0,e=0;
    for(int i=0;i<n;i++)
    {
        total_pages+=books[i];
        s= max(s,books[i]);
    }
    e=total_pages;
    int final_ans=0;
    while(s<=e)
    {
        ll mid = (s+e)/2;
        if(isvalid(books,n,k,mid))
        {
            final_ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return final_ans;
}
int main()
{
    ll n;
    ll k;
    cin>>n>>k;
    ll books[10005];
    for(int i=0;i<n;i++)
    {
        cin>>books[i];
    }
    cout<<binarysearch(books,n,k);

}
