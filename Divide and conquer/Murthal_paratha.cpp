#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v, int p, int l  ,int mid)
{
    int inx = 1;
    int index = 0;
    while(p)
    {
        if((v[index]*inx*(inx+1))<=mid*2)
        {
            p--;
            inx++;
        }
        else
        {
            index++;
            if(index==l)
            {
                return false;
            }
            inx = 1;
        }
    }
    return true;
}
int solve(vector<int> &v, int p, int l)
{
    // time reuires to 1st parathn by 1st cook R
    int s = v[0];
    // max time to complete total paramth by last cooks
    int e = v[l-1]*(p*(p+1))/2;
    int ans;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(check(v,p,l,mid))
        {
            ans = mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main() {
    int p;
    cin>>p;
    int l;
    cin>>l;
    vector<int> v(l);
    for(int i=0;i<l;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    cout<<solve(v,p,l);
}
