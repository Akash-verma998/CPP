#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool compare(string a,string b)
{
    int found;
    if (a.length()>b.length())
    {
        found = a.find(b);
    }
    else
    {
       found = a.find(b);
    }
    if(found!=-1){
        return a>b;
    }
    return a<b;
}
int main()
{
    int n;
    cin>>n;
    string v[n];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(v,v+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<"\n";
    }
    return 0;
}

