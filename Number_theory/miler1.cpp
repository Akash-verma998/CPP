/*
Modular exponentation :  (a^b)%n
Modular Multiplication : (a*b)%n

*/

#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int modular_multi(int a, int b, int n)
{
	int res = 0;
	while(b)
	{
		if(b&1)
			res+=a;
		a*=2;
		b/=2;
		res%=n;
		a%=n;
	}
	return res;
}
int modualar_exponenetation(int a,int b,int n)
{
	int res = 1;
	while(b)
	{
		if(b&1)
		{
			res = modular_multi(res,a,n);
		}
		a = modular_multi(a,a,n);
		a%=n;
		b/=2;
	}
	return res;
}
bool miller_robin(int n)
{
	if(n==1)
	{
		return false;
	}
	if(n==2)
	{
		return true;
	}
	if(n%2==0)
		return false;
	int d=n-1,s=0;
	while(d%2==0)
	{
		s++;
		d/=2;
	}
	vector<int> a({2,3,5,7,11,13,17,19,23}); //random number
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>n-2)
			continue;
		int ad = modualar_exponenetation(a[i],d,n);
		if(ad%n==1)
		{
			continue;
		}
		bool prime = false;
		for(int r=0;r<=s-1;r++)
		{
			int rr = modualar_exponenetation(2,r,n);
			int ard = modualar_exponenetation(ad,rr,n);
			if(ard%n==n-1)
			{
				prime = true;
				break;
			}
		}
		if(prime==false)
			return false;
	}
	return true;

}
void solve()
{
	int n;
	cin>>n;
	if(miller_robin(n))
	{
		cout<<"prime\n";
	}
	else
	{
		cout<<"not prime\n";
	}
}
main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

