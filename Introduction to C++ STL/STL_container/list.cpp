#include<iostream>
#include<list>
using namespace std;
int main()
{
    /*
    It basically doubly linked list
    it is very useful
    when we need to add element in in between the array
    and delete element from the list

    bcz in array and in vector we need to shift the element
    when insert and delete element from the array

    */
    list<int> l;
    list<int> l1 = {1,2,3,45,6,7};
    list<string> l2 = {"hello","how","are","you"};
    l2.push_back("pineapple");
    l2.sort();
    l2.reverse();
    cout<<l2.front()<<endl;
    l2.pop_front();
    l2.push_front("kiwi");
    string p = "kiwi";
    l2.remove(p);


    // erase one or two elements
    auto it  = l2.begin();
    it++;
    it++;
    l2.erase(it);// work on index
    // insert the element
    auto it2 = l2.begin();
    it2++;
    l2.insert(it2,"Juice");
    for(auto s:l2)
    {
        cout<<s<<endl;
    }
}
