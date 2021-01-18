#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1,2,34,40,40,40,50,60};
    int n = sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    //return boolean value
    bool it  = binary_search(a,a+n,key);
    if(it)
    {
        cout<<"Element is present\n";
    }
    else
        cout<<"Not Present\n";

    /* two more this
    get the index of the
    upper_bound and lower_bound
    */
    auto it1 = lower_bound(a,a+n,40);
    cout<<"Lower bound is present at: "<<(it1-a)<<endl;
    if((it1-a)==n)
        cout<<"element is not present";

    auto it2 = upper_bound(a,a+n,40);
    cout<<"Upper bound is present at: "<<(it2-a)<<endl;
    if((it2-a)==n)
        cout<<"element is not present";
     /*
     lower bound and upper bound take log time so in log n time we can find frequency
     of the element  it is very best approach to find element frequency
     but array should be sorted order
     */
    cout<<"frequency "<<it2-it1<<endl;
}
