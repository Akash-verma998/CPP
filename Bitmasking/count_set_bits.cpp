#include<iostream>
using namespace std;
/*Complexity = O(lag n) bcz N can contains maximum log n bits... that is worst case
largest number in long long int we can store is 10^18 and that have 64 bits */
int countbits1(int n)
{
    int ans =0;
    while(n>0)
    {
        int p = n&1;
        if(p==1)
            ans+=1;
        n=n>>1;
    }
    return ans;
}
/* O(number of set bits in the n) very efficient it also can be log n */
int countbitsfast(int n)
{
    int ans = 0;
    while(n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int p1=countbits1(n);
    cout<<countbitsfast(n);
    cout<<__builtin_popcount(n);
    cout<<p1<<endl;
}
