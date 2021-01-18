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
		b[0]=1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
			sum=sum%n;
			sum=(n+sum)%n;
			b[sum]++;
		}
		cout<<endl;
		long long ans =0;
		for(int i=0;i<n;i++)
		{
			long long m=b[i];
			ans +=m*(m-1)/2;
		}
		cout<<ans<<endl;

	}
	return 0;
}
