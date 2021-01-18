#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define matrix vector<vector<ll>>
ll m,n,MOD;
int k;
vector<ll> c;
vector<ll> b;
matrix mul(matrix A,matrix B)
{
    matrix C(k+2,vector<ll>(k+2));
    for(int i=1;i<=k+1;i++)
    {
        for(int j=1;j<=k+1;j++)
        {
            for(int x=1;x<=k+1;x++)
            {
                C[i][j] = (C[i][j] + A[i][x]*B[x][j])%MOD;
            }
        }
    }
    return C;
}
matrix pow(matrix A, ll p)
{
    if(p==1)
        return A;
    if(p&1)
        return mul(A, pow(A,p-1));
    matrix X = pow(A,p/2);
    return mul(X,X);
}
ll fib(ll n)
{
   //base case
   if(!n)
        return 0;
   // if n is less than k
   //our answer lies in already created F1 vector
   if(n<=k)
   {
       return b[n-1];
   }
   //step2 . Determine the F1 vector
   vector<ll> F1(k+2);
   for(int i=2;i<=k+1;i++)
   {
       F1[i]=b[i-2];
   }
   matrix T(k+2,vector<ll>(k+2));
   for(int i=1;i<=k+1;i++)
   {
       for(int j=1;j<=k+1;j++)
       {
           //put 1 at (1,1)
           if(i==1 && j==1)
           {
               T[i][j]=1;
               continue;
           }
           //if i==k+1 last row
           //for last row put the coefficient vector
           if(i==k+1 && j>1)
           {
               T[i][j] = c[k-j+1];
               continue;
           }
           //put l in all (i,j+1) positions
           if(j==i+1)
           {
               T[i][j]=1;
               continue;
           }
           //else 0 in (i,j)
           T[i][j] = 0;
       }
   }
   //use matrix exponentiation to find T^n
   T=pow(T,n);
   //answer is the first row of T^n*F1
   ll res = 0;
   for(int i=1;i<=k+1;i++)
   {
       res = (res+T[1][i]*F1[i])%MOD;
   }
   return res%MOD;
}
int main()
{
    int t;
    ll a;
    cin>>t;
    while(t--)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a;
            b.push_back(a);
        }
        for(int i=1;i<=k;i++)
        {
            cin>>a;
            c.push_back(a);
        }
        cin>>m>>n>>MOD;
        ll result= fib(n)-fib(m-1);
        // to handle negative case
        if(result <0)
            result+=MOD;
        cout<<result<<endl;;
        c.clear();
        b.clear();
    }
    return 0;
}
