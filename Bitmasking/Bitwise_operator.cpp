#include<iostream>
using namespace std;
int main()
{
//    // Bitwise operator {, &,|,~,<<(left_shift),>>(right_shift)
//    // a<<1=a*2, a<<2=a*2^2, a<<n=a*2*n
//    // a>>1=a/2, a>>2=a/2^2, a<<n=a/2^n
//    // i)very fast ii)in computer everything in bits
//    // Q.1) find unique in 2*n+1 in number where only 1 is unique. concept 5^2^5=2
//    int a[5]={1,2,3,2,1};
//    int p=a[0];
//    for(int i=1;i<5;i++)
//    {
//        p=p^a[i];
//    }
//    cout<<p<<"\n";
//
//
//    // odd and even number
//    int s=4;
//    int b=5;
//    if(s & 1)
//    {
//        cout<<"odd\n";
//    }
//    else{
//        cout<<"even\n";
//    }
//    if(b & 1)
//    {
//        cout<<"odd\n";
//    }
//    else{
//        cout<<"even\n";
//    }
//    // how much add in 11 it become 15
//    int x=11^15;
//    cout<<x<<"\n";
//
//    //calculate number of set bits of 1;
//    int c=2;
//    int coun=0;
//    while(c>0)
//    {
//        coun+=(c&1);
//        c=c>>1;
//    }
//    cout<<coun<<endl;

    // second approach
    int c=1;
    int coun=0;
    while(c)
    {
        coun++;
        c=c&(c-1);
    }
    cout<<coun<<"\n";

    //XOR swapping

    int l=7;
    int m=6;
    l=l^m; // 7^6
    m=m^l; // 6^7^6
    l=l^m; // 7^6^7
    cout<<l<<endl<<m;

    //Extract ith bit of the number
    int num =5;
    int i=0;
    int q=num & (1<<i);
    if(q)
    {
        cout<<"\n1";
    }
    else
    {
        cout<<"\n0";
    }

    // set ith bits
    int nu = 13;
    i=1;
    int mask=1<<i;
    nu=(nu|mask);
    cout<<"\n"<<nu; // 15 1101 --> 1111

    //remove the ith bits

    int nu1=13;
    i=2;
    mask = ~(1<<i);
    nu1=nu1&mask;
    cout<<"\n"<<nu1;  //1101 -> 1001

}
