#include<iostream>
#include<vector>
using namespace std;
int main()
{
    //vector<int> * vp = new vector<int>(); // dynamic delete by yourself
    vector<int> v; //statically , delete itself after execution
    //[]--> only use for update and get not use for insert
    for(int i=1;i<=100;i++)
    {
        v.push_back(i);
        cout<<v.size()<<endl;
        cout<<v.capacity()<<endl;
    }
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
//    v[3]=100;
//    v[4]=123;
    v[2]=1000;
    v.pop_back();
    for(int i=0;i<2;i++)
    {
        cout<<v.at(i)<<" ";
    }


}
