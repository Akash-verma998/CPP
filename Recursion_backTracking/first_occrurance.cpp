#include<iostream>
using namespace std;
int focc(int a[],int n,int key)
{
	if(n==0)
	{
		return -1;
	}
	if(a[0]==key)
	{
		return 0;
	}
	int i = focc(a+1,n-1,key);
	if(i==-1)
	{
		return -1;
	}
	return i+1;
}
int locc(int a[],int n,int key)
{
	if(n==0)
		return -1;
	int i = locc(a+1,n-1,key);
	if(i==-1)
	{
		if(a[0]==key)
			return 0;
		else
			return -1;
	}
	return i+1;
}
int allocc(int a[],int i,int n,int *out,int key,int j)
{
	if(i==n)
	{
		return j;
	}
	if(a[i]==key)
	{
		out[j] = i;
		return allocc(a,i+1,n,out,key,j+1);
	}
	return allocc(a,i+1,n,out,key,j);

}
int main()
{
	int a[]= {10,23,12,34,56,7,23,67};
	int n= sizeof(a)/sizeof(int);
	int key;
	cin>>key;
	int p = focc(a,n,key);
	int p2 = locc(a,n,key);
	int out[100];
	int p3 = allocc(a,0,n,out,key,0);
	cout<<p<<endl;
	cout<<p2<<endl;
	for (int i=0;i<p3;i++)
	{
		cout<<out[i]<<" ";
	}
}
