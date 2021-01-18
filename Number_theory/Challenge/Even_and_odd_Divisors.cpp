#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[100000]={0};
void sieve()
{
	for(int i=1;i<100000;i++)
	{
		for(int j=i;j<100000;j+=i)
		{
			if(i%2==0)
			{
				sum[j]+=i;
			}
			else
			{
				sum[j]-=i;
			}
		}
	}

}
int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<sum[n]<<endl;
	}
	return 0;
}
