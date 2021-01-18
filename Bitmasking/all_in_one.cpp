#include<iostream>
using namespace std;
bool isodd(int n)
{
    return n&1;
}
int getbit(int n,int i)
{
    int mask = 1<<i;
    int ans = (n&mask)>0?1:0;
    return ans;
}
int setbit(int n,int i)
{
    int mask = 1<<i;
    int ans = n | mask;
    return ans;
}
int clearbit(int n,int i)
{
    int mask = ~(1<<i);
    int ans = n & mask;
    return ans;
}
int updatebit(int n, int i, int v)
{
    int mask = ~(1<<i);
    int clrn = n&mask;
    int ans = n|(v<<i);
    return ans;
}
int clearlstbit(int n,int i)
{
    int mask = (-1<<i);
    return n&mask;
}
int clearrange(int n,int j int i)
{
    int a = (-1<<(j+1));
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}

int main()
{
    int n,i;
    cin>>n;
    cin>>i;
    bool p1 = isodd(n);
    int p2 = getbit(n,i);
    int p3 = setbit(n,i);
    cout<<p1<<p2<<p3;
}
