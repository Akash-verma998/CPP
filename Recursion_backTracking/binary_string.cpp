#include<iostream>
using namespace std;
int binarystr(int n)
{
	if(n==0)
		return 1;
	if(n==1)
		return 2;
	int p = binarystr(n-1)+binarystr(n-2);
	return p;
}
int main()
{
	int n;
	cin>>n;
	int p = binarystr(n);
	cout<<p<<endl;
}
