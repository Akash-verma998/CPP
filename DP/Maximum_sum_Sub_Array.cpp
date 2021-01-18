#include<iostream>
using namespace std;
int maxSum(int a[], int n)
{
    int dp[100]={0};
    dp[0]=a[0]>0?a[0]:0;
    int max_so_for =dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1]+a[i];
        if(dp[i]<0)
            dp[i]=0;
        max_so_for = max(dp[i],max_so_for);

    }
    return max_so_for;
}
// Space optimized code
int maxSumSO(int a[],int n)
{
    int x ,y;
    x = a[0]>0?a[0]:0;
    int max_so_for = x;
    for(int i=1;i<n;i++)
    {
       x= x+a[i];
       if(x<0)
            x=0;
       max_so_for = max(max_so_for,x);
    }
    return max_so_for;
}
int main()
{
    int a[]={-3,2,5,-1,6,3,-2,7,-5,2};
    int n=sizeof(a)/sizeof(int);
    cout<<maxSum(a,n)<<endl;
    cout<<maxSumSO(a,n)<<endl;
    return 0;
}
