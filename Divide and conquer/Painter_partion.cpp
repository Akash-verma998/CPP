#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &v, int n, int k,int mid)
{
    int temp = 0;
    int x = 1; 
    for(int i=0;i<n;i++)
    {   
        if(temp+v[i]<= mid)
        {
            temp += v[i];
        }
        else
        {
            x++;
            temp = v[i];
            if(x>k) 
            return false;   
        }
    }  
    return true;
}
int solve(vector<int> &v, int n, int k, int sm ,int max)
{
    // time reuires to 1st parathn by 1st cook R
    int s = max;
    // max time to complete total paramth by last cooks
    int e = sm;
    int ans=s;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(check(v,n,k,mid))
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
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int> v(n);
    int sm=0;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sm+=v[i];
        if(v[i]>max)
        {
            max=v[i];
        }
    }
    sort(v.begin(),v.end());
    cout<<solve(v,n,k,sm,max)<<endl;
}
