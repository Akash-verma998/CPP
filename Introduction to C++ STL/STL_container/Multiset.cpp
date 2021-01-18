/*
Multiset -  that can store multiple elements that have same elements
stored in a specific -> stored according to internal comparison object.
values can be inserted and modified
associative container -> elements are refered by the value and not by the index
underlying data structure bst
*/
#include<iostream>
#include<set>
using namespace std;
typedef multiset<int>:: iterator It;
int main()
{
    int arr[] = {10,20,30,20,10,10};
    multiset<int> m(arr,arr+6);
    m.erase(20);
    m.insert(60);
    for(int x: m)
    {
        cout<<x<<",";
    }
    //count
    cout<<"count: "<<m.count(10)<<endl;
    //find
    auto it = m.find(50);    //if not find return nth index
    cout<<(*it)<<endl;

    //get all elements which are equal to 30
    pair<It,It> range =  m.equal_range(30);
    for(auto it=range.first;it!=range.second;it++)
    {
        cout<<*it<<"-";
    }
    cout<<endl;
    // Lower >= and upper_bound>
    for(auto it = m.lower_bound(10);it!=m.upper_bound(50);it++)
    {
        cout<<*it<<"-";
    }


}

