#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    vector<long unsigned int> v;
    while(true)
    {
        cin>>n;
        if(n==42)
            break;
        v.push_back(n);
    }
    for(long unsigned int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}

