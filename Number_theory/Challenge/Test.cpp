#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
int maxScore(vector<int> a,int m) {
    int ans=0;
    int p=0;
    int n = a.size();
    sort(a.begin(),a.end());
    int i=0;
    while(i<n)
    {
        if(i%m==0)
        {
            if(n-i>=m)
            {
               p++;
            }
        }
        ans=(ans+(p*a[i])%1000000007)%1000000007;
        cout<<p<<" "<<a[i]<<endl;
        i++;
    }
    return ans;

}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<maxScore(v,m)<<endl;
}
