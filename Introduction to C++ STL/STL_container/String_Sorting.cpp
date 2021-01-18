#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool compare(string a, string b)
{
    if(a.size()==b.size())
    {
        return a<b;
    }
    return a.size()<b.size();
}
int main()
{
    /*
    int n;
    cin>>n;
    cin.get();// vector
    string s[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);
    }
    sort(s,s+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
    */
    char c[100] = "Hello i am software engineering";
    char *ptr = strtok(c," ");
    cout<<ptr<<endl;
    /*
    char *ptr1= strtok(NULL," ");
    cout<<ptr1;
    */
    // to extract all the token
    while(ptr!=NULL)
    {
        char *ptr = strtok(NULL," ");
        cout<<ptr<<endl;
    }
    return 0;
}
