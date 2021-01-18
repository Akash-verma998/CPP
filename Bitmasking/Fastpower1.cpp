#include<iostream>
using namespace std;
long long m = 1000000007;
long long power(long long a, long long b)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,n;
        cin>>a>>n;
        long long p = power(a,n);
        cout<<p<<endl;
    }
    return 0;
}

