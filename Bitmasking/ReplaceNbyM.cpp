/*
you are given a 32-bits number N and M put M in N and given index.
N=10000000000
M=10101 i=2 j=6
new = 10001010100
point :
1. First clear bit in n for given range
2. Then remove that bits by n
*/

#include<iostream>
using namespace std;
int replaceNbyM(int n, int m, int i, int j)
{
    int a = -1<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    n = n&mask;
    m=m<<i;
    return n|m;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m>>i>>j;
    int ans = replaceNbyM(n,m,i,j);
    cout<<ans;
}
