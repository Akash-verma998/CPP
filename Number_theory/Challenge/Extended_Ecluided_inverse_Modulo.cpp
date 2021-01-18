#include<iostream>
using namespace std;
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return ((a*b)/gcd(a,b));
}
int x,y,GCD;
void extendedEuclidMethod(int a, int b)
{
    //Base case
    if(b==0)
    {
        x=1;
        y=0;
        GCD=a;
        return ;
    }
    // recursive
    extendedEuclidMethod(b,a%b);
    int Cx = y;
    int Cy = x-(a/b)*y;
    x=Cx;
    y=Cy;

}
int inverseModulo(int a, int m)
{
	extendedEuclidMethod(a,m);
	return (x+m)%m;
}
int main()
{
	/*
    int n1,n2;
    cin>>n1>>n2;
    int p = inversedulo(n1,n2);
    cout<<p<<endl;
    */
    /*
    extendedEuclidMethod(n1,n2);
    cout<<x<<" "<<y;
    int p = gcd(n1,n2);
    int l=lcm(n1,n2);
    cout<<p<<endl;
    cout<<l<<endl;
    */
    cout<<inverseModulo(6,7)<<endl;
    return 0;
}
