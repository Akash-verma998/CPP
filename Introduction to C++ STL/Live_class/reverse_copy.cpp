#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;;

int main()
{
    vector<char> v(10);
    for(int i=0;i<10;i++)
    {
        cin>>v[i];
    }
    vector<char> v2(10);
    reverse_copy(v.begin(),v.end(),v2.begin());
    for(int i=0;i<10;i++)
    {
        cout<<v2[i]<<" ";
    }
    return 0; // lower_bound, merge, next_permutation
}
