#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define matrix vector<vector<ll>>
#define MOD 98765431
ll n1,t;
vector<ll> c;
vector<ll> b;
vector<ll> res;
matrix mul(matrix A,matrix B)
{
    matrix C(n1+1,vector<ll>(n1+1));
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n1;j++)
        {
            for(int x=1;x<=n1;x++)
            {
                C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
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
void fib(ll n)
{
   //base case
   if(!n)
        return ;
   vector<ll> F1(n1+1);
   for(int i=0;i<n1;i++)
   {
       F1[i+1]=b[i];
   }
   matrix T(n1+1,vector<ll>(n1+1));
   for(int i=1;i<=n1;i++)
   {
       for(int j=1;j<=n1;j++)
       {
           //put 1 at (1,1)
           if(i==j)
           {
               T[i][j]=0;
               continue;
           }
           T[i][j] = 1;
       }
   }
   //use matrix exponentiation to find T^n
   T=pow(T,n);
   ll ans=0;
   //answer is the first row of T^n*F1
   for(int i=1;i<=n1;i++)
   {
       for(int j=1;j<=n1;j++)
       {
           ans=(ans+(T[i][j]*F1[j])%MOD)%MOD;
       }
       cout<<ans<<endl;
       ans=0;
   }
}
int main()
{
    ll a;
    cin>>n1>>t;
    for(int i=1;i<=n1;i++)
    {
        cin>>a;
        b.push_back(a);
    }
    fib(t);
    return 0;
}

