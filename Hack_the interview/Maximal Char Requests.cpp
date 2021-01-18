#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        string news;
        int max=-1;
        char ch='\n';
        for(int i=a;i<=b;i++)
        {
            news+=s[i];
            if(int(s[i])>max)
            {
                max = int(s[i]);
                ch = s[i];
            }
        }
        int count=0;
        int n1=news.size();
        for(int i=0;i<n1;i++)
        {
            if(news[i]==ch or int(news[i]+32)==int(ch))
                count++;
        }
        cout<<count<<endl;
    }
}
