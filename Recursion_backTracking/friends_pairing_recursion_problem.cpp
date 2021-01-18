#include<iostream>
using namespace std;
long long int friendpair(int n)
{
	if(n==1 || n==0)
		return 1;
	long long int p = 1*friendpair(n-1)+ (n-1)*friendpair(n-2);
	return p;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int p = friendpair(n);
		cout<<p<<endl;
	}
}
