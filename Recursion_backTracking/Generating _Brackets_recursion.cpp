#include<bits/stdc++.h>
using namespace std;
void generates_brackets(char *out,int n, int idx, int open, int close)
{
	//base case
	if(idx==2*n)
	{
		out[idx] = '\0';
		cout<<out<<endl;
		return ;
	}
	//rec case
	//2 options
	if(open < n)
	{
		out[idx] = '(';
		generates_brackets(out,n,idx+1,open+1,close);
	}
	if(close<open)
	{
		out[idx]=')';
		generates_brackets(out,n,idx+1,open,close+1);
	}
	return ;
}
int main()
{
	int n;
	cin>>n;
	char out[1000];
	int idx = 0;
	generates_brackets(out,n,0,0,0);
	return 0;
}