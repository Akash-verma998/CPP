#include<iostream>
using namespace std;
int countbits(int n)
{
    int ans =0;
    while(n)
    {
        int p = n&(-n);
        n=n-p;
        ans++;
    }
    return ans;
}
int main()
{
    cout<<countbits(4)<<endl;
}
