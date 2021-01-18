#include<bits/stdc++.h>
using namespace std;
bool compare(int a, int b)
{
    return a>b;
}
int main()
{
    vector<int> d{1,2,3,10,14};
    //push_back O(1) for most of the time

    d.push_back(16);

    //pop_back remove the last element O(1) time
    d.pop_back();

    //insert some element in middle O(N)
    d.insert(d.begin()+3,4,100);

    d.erase(d.begin()+3);
    d.erase(d.begin()+2,d.begin()+5);
    for(int x:d)
    {
        cout<<x<<",";
    }
    d.clear(); // remove all the element does't delete the memory

    if(d.empty())
    {
        cout<<"This is an empty vector";
    }
    vector<int> v;
    int n;
    cin>>n;
    // here is doubling.
    // we should avoid this.
    // use reserve
    v.reserve(1000); //it's avoid doubling
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    v.pop_back();
    sort(v.begin(),v.end()+1,compare);
    // print these
    for(int i=0;i<=v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    //v.clear() // to delete the v
    // v.max_size() // gives max size that vector can store
    // v.capacity() // capacity of the vector
}
