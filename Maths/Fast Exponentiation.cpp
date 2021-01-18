#include<iostream>
using namespace std;
int power(int a, int b)
{
    //base case
    if(b==0)
    {
        return 1;
    }
    //recursive case
    int smallres=power(a,b/2);
    smallres*=smallres;
    if(b&1)
    {
        smallres*=a;
    }
    return smallres;
}
int main()
{
    //a=a(a^b/2)^2 when b is odd
    //a=(a^b/2)^2 when b is even
    int a,b;
    cin>>a>>b;
    int p=power(a,b);
    cout<<p;
}
