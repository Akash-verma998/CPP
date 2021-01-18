#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string s0;
    string s1="Hello world";
    string s2(s1);
    string s3=s1;
    char a[]={'a','b','c','\0'};
    string s4(a);


    s0.append("I love c++");
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s1<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;

    s0+=" and Python";
    cout<<s0<<endl;
    // compare Lexo graphical Comparison
    string sp = "Apple";
    string sq = "Mango";
    cout<<sp.compare(sq)<<endl;


    //Find substring
    string t ="I know you very well";
    int  p = t.find("know");
    cout<<p<<endl;
    for(auto it=sp.begin();it!=sp.end();it++)
        cout<<(*it)<<endl;
    for(auto c:sp)
        cout<< c<<" ";
    return 0;
}
