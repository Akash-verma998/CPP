/*
Modular exponentation :  (a^b)%n
Modular Multiplication : (a*b)%n

*/

#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll modular_multi(ll a, ll b, ll n)
{
	ll res = 0;
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
ll modualar_exponenetation(ll a,ll b,ll n)
{
	ll res = 1;
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
bool miller_robin(ll n)
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
	ll d=n-1,s=0;
	while(d%2==0)
	{
		s++;
		d/=2;
	}
	vector<ll> a({2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,57,61,69,71}); //random number
	for(ll i=0;i<a.size();i++)
	{
		if(a[i]>n-2)
			continue;
		ll ad = modualar_exponenetation(a[i],d,n);
		if(ad%n==1)
		{
			continue;
		}
		bool prime = false;
		for(ll r=0;r<=s-1;r++)
		{
			ll rr = modualar_exponenetation(2,r,n);
			ll ard = modualar_exponenetation(ad,rr,n);
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
	ll n;
	cin>>n;
	if(miller_robin(n))
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

