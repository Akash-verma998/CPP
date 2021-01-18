#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        getline(cin,s);
        int mid = s.size()/2;
        if(s.size()%2==1)
        {
            map<char,int> m1,m2;
            string s1="",s2="";
            for(int j=0;j<mid;j++)
            {
                s1+=s[i];
                m1[s[i]]++;
            }
            for(int j=mid+1;j<s.size();j++)
            {
                s2+=s[i];
                m2[s[i]]++;
            }
            cout<<s1<<" "<<s2;
//            bool yes  = true;
//            for(int j=0;j<s1.size();j++)
//            {
//                cout<<s1[j]<<" "<<m1[s1[j]]<<" "<<m2[s1[j]]<<endl;
//                if(m1[s1[j]]!=m2[s1[j]])
//                {
//                    yes=false;
//                    break;
//                }
//            }
//            if(yes)
//                cout<<"YES\n";
//            else
//                cout<<"NO\n";
        }
//        else
//        {
//            string s1="",s2="";
//            map<char, int> m1,m2;
//            for(int j=0;j<mid;j++)
//            {
//                s1+=s[i];
//                m1[s[i]]++;
//            }
//            for(int j=mid;j<s.size();j++)
//            {
//                s2+=s[i];
//                m2[s[i]]++;
//            }
//            bool yes  = true;
//            for(int i=0;i<s1.size();i++)
//            {
//                cout<<s1[i]<<" "<<m1[s1[i]]<<" "<<m2[s1[i]]<<endl;
//                if(m1[s1[i]]!=m2[s1[i]])
//                {
//                    yes=false;
//
//                }
//            }
//            if(yes)
//                cout<<"YES\n";
//            else
//                cout<<"NO\n";
//        }
    }
}
