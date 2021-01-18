#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a<b;
}
int main()
{
    vector<int> v;
    int q,k;
    cin>>q>>k;
    for(int i=0;i<q;i++)
    {
        int temp;
        cin>>temp;
        if (temp==1)
        {
            int x,y;
            cin>>x>>y;
            v.push_back(x*x+y*y);
        }
        if (temp==2)
        {
            sort(v.begin(),v.end(),compare);
            cout<<v[k-1];
        }
    }
}
