#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s("hello world");
    cout<<s<<endl;
    string s2 = "It is S2 String";
    cout<<s2<<endl;
    cout<<s2.length()<<endl;
    for(int j=0;j<s2.length();j++)
    {
        cout<<s2[j]<<"-";
    }
    cout<<"\n";
    string s3;
    getline(cin,s3);
    cout<<s3<<endl;
    string arr[] = {"Apple","Akash","Anshul","Orange"};
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
}
