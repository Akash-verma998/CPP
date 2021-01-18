#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int n=s1.length();
        int n1 = (int) bitset<64>(s1).to_ulong();
        int n2 = (int) bitset<64>(s2).to_ulong();
        int p=n1^n2;
        string ans="";
        while(p>0)
        {
            int coun=(p&1);
            p=p>>1;
            ans+=to_string(coun);
        }
        int remain_n=n-ans.length();
        for(int j=0;j<remain_n;j++)
        {
            cout<<0;
        }
        for(int i=ans.length()-1;i>-1;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
}
