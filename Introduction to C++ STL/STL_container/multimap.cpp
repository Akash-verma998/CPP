#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    multimap<char,string> m;
    for(int i=0;i<10;i++)
    {
        char a;
        string b;
        cin>>a>>b;
        m.insert(make_pair(a,b));
    }
    for(auto p:m)
        cout<<p.first<<" "<<p.second<<endl;
    auto it = m.begin();
    m.erase(it);
    auto it2=m.lower_bound('b'); // key that >=b
    auto it3 = m.upper_bound('c');// key that lower than d
    for(auto it4=it2; it4!=it3;it4++)
        cout<<it4->second<<endl;
}
