/*
if (2*3*5*7) //even then u(n)=1;
if (2*3*5) odd u(n) = -1;
otherwise u(n) = 0;
#include<iostream>
using namespace std;
int N=105;
int a[105],prime_count[105],mobius[105];
void cal_mobius()
{
	int i,j;
	for(i=1;i<N;i++)
	{
		a[i]=1;
	}
	for(i=2;i<N;i++)
	{
		if(prime_count[i])
			continue;
		for(j=i;j<N;j+=i)
		{
			prime_count[j]++;
			a[j]*=i;
		}
	}
	for(i=1;i<N;i++)
	{
		if(a[i]==i)
		{
			if(prime_count[i]%2==1)
			{
				mobius[i] = -1;
			}
			else
			{
				mobius[i] = 1;
			}
		}
		else
		{
			mobius[i] = 0;
		}
	}
}
main()
{
	cal_mobius();
	for(int i=1;i<30;i++)
	{
		cout<<i<<" "<<mobius[i]<<endl;
	}
}

*/


#include<iostream>
using namespace std;
int main()
{

}
