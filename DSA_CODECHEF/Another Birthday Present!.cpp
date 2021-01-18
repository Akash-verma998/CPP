#include<bits/stdc++.h>
using namespace std;
map<int, int> m;
bool issorted(vector<int> a,vector<int> a1,int k,int n)
{
    bool ans = true;
    for(int i=0;i<k;i++)
    {
        int index = m[a[i]];
        index = abs(i-index);
        if((index%n)!=0)
            return false;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> a,a1;
        int k,n;
        cin>>k>>n;
        for(int i=0;i<k;i++)
        {
            int temp;
            cin>>temp;
            a.push_back(temp);
            a1.push_back(temp);
            m[temp] = i;
        }
        sort(a.begin(),a.end());
        bool p = issorted(a,a1,k,n);
        if(p)
        {
            cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
    return 0;
}
