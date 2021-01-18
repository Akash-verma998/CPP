#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int> v1,v2;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v1.push_back(temp);
        }
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            v2.push_back(temp);
        }
        int m1=99999,m2=99999;
        for(int i=0;i<n;i++)
        {
            if(v2[i])
            {
                if(m1>v1[i])
                {
                    m1=v1[i];
                }
            }
            else
            {
                if(m2>v1[i])
                {
                    m2=v1[i];
                }
            }
        }
        v1.clear();
        v2.clear();
        if((s+m1+m2)<=100)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
