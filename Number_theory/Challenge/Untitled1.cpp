
#include<iostream>
using namespace std;
const int n=1000000;
long long phi[n+1];
void computeTotient(int n)
{
    for (int i=1; i<=n; i++)
        phi[i] = i;
    for (int p=2; p<=n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;
            for (int i = 2*p; i<=n; i += p)
            {
               phi[i] = (phi[i]/p) * (p-1);
            }
        }
    }
}
int main()
{
    computeTotient(n);
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        cout<<phi[q]<<endl;
    }
    return 0;
}
