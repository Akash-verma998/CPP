#include<iostream>
using namespace std;
int main() {
    long long a[100005],b[100005]={0};
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			b[i]=0;
		}
		long long sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			sum=sum%n;
			sum=(n+sum)%n;
			b[sum]++;
		}
		for(int i=0;i<n;i++)
		{
			cout<<b[i]<<endl;
		}
	}
	return 0;
}
