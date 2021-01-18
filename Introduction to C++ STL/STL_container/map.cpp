#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int> m;

    //insert
    m.insert(make_pair("Akash",100));
    pair<string,int> p;
    p.first="Anshul";
    p.second=100;
    m.insert(p);
    m["Banana"]=20;

    //search
    auto it = m.find("Akash");
    if(it!=m.end())
        cout<<m["Akash"];

    //erase
    m.erase("Akash");

}
