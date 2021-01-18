#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> m;
    m["mango"]=10;
    // secobd method
    m.insert(make_pair("Apple",120));
    if(m.count("Apple")==1)
    {
        cout<<"Price of apple: "<<m["Apple"];
    }
    auto f = m.find("mango");
    if(f!=m.end())
    {
        cout<<"Price of mango is:"<<(f->second)<<endl;
    }
    else{
        cout<<"Mango is not exist";
    }
    return 0;
    //m.erase("mango"); to delete the particular key.
}
