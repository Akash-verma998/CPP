#include<iostream>
#include<cstring>
using namespace std;
int string_toint(char *a,int n)
{
	if(n==0)
	{
		return 0;
	}
	int digit = a[n-1] - '0';
	int p = string_toint(a,n-1);
	return p*10 + digit;
}
int main()
{
	char a[]="1234";
	int len = strlen(a);
	int p = string_toint(a,len);
	cout<<p+2<<endl;
	cout<<p<<endl;
}
