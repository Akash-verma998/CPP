/*

m n
m<=10^7
n<=10^250
gcd(a,b) = gcd(a%b,b)  = gcd(b%a,a)

x = m%n
m=1 2 1 1 2
n=
1 2 1 1 2 = (1*10^4 + 2*10^3 + 1*10^2 + 1*10 + 2*10^0)%10^7

y = ((1%7)*(10^4%7) + (2%7)*(10^3%7)...........)
gcd(y,n) =  answer of the question
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a, int b)
{
    return b==0?a:gcd(b,a%b);
}
int fastexpomodulo(int a, int b, int m)
{
    ll res=1;
    while(b>0)
    {
        if(b&1){
            res = (res*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return res;
}
int main()
{
	int n;
	cin>>n;
	string m;
	cin>>m;
	int m_size = m.size();
	int y=0;
	if(n==0)
	{
		cout<<m<<endl;
		return 0;
	}
	for(int i=m_size-1;i>=0;i--)
	{
		y = y + ((m[m_size-1-i]-'0')*(fastexpomodulo(10,i,n))%n)%n;
		y=y%n;
	}
	int ans = 1;
	ans = gcd(y,n);
	cout<<ans<<endl;
	return 0;
}
