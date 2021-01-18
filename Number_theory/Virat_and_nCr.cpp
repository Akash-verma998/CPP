#include<bits/stdc++.h>
using namespace std;
int p=1000000007;
int Cal_nCr_mod_p(int n, int r, int p)
{
int C[r+1];
memset(C, 0, sizeof(C));
C[0] = 1;
for (int i = 1; i <= n; i++)
{
for(int j = min(i, r); j > 0; j--)
C[j] = (C[j] + C[j-1])%p;
}
return C[r];
}
int LucasApproach(int n, int r, int p)
{
if(r==0)
return 1;
else
{
int n_i = n%p, r_i = r%p;
int result = (LucasApproach(n/p, r/p, p)*Cal_nCr_mod_p(n_i,r_i,p))%p;
return result;
}
}
int main()
{
int n,r;
cin>>n>>r;
int result = LucasApproach(n,r,p);
cout<<result<<endl;
}
