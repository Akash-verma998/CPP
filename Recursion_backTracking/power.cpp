#include<iostream>
using namespace std;
int power(int a,int b)
{
    if(b==0){
        return 1;
    }
    else{
        return a*power(a,b-1);
    }
}
int fast_power(int a, int b)
{
    if (b==0)
        return 1;
    int smallpower = power(a,b/2);
    smallpower=smallpower*smallpower;
    if(b&1){
        smallpower=a*smallpower;
    }
    return smallpower;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    cout<<fast_power(a,b)<<endl;
    return 0;
}
