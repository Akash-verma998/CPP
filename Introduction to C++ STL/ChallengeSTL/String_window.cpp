#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    string st1,st2;
    getline(cin,st1);
    getline(cin,st2);
    int n1=st1.length();
    int n2=st2.length();
    int min_window=INT_MAX;
    int si=-1;
    int se=-1;
    int s=0;
    unordered_map<char,int>map1;
    unordered_map<char,int>t;
    for(int i=0;i<n2;i++)
    {
        map1[st2[i]]++;
    }
    for(int i=0;i<n1;i++)
    {
        bool c = true;
        t[st1[i]]++;
        for(auto it=map1.begin();it!=map1.end();it++)
        {
            if(it->second>t[it->first])
            {
                c=false;
                break;
            }
        }
        if(c)
        {
            while(t[st1[s]]>map1[st1[s]])
            {
                t[st1[s]]--;
                s++;
            }
            if(min_window>i-s)
            {
                min_window=i-s;
                si=s;
                se=i;
            }
        }
    }
    if(min_window==INT_MAX)
    {
        cout<<"No string";
    }
    else
    {
        for(int i=si;i<=se;i++)
        {
            cout<<st1[i];
        }
    }
    return 0;
}
