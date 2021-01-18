#include<iostream>
using namespace std;
unsigned int a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n>70)
    {
        cout<<"YES\n";
        return 0;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int s=k+1;s<n;s++)
                    {
                        if((a[i]^a[j]^a[k]^a[s])==0)
                        {
                            cout<<"YES\n";
                            return 0;
                        }
                    }
                }
            }
        }

    }
    cout<<"NO\n";
}
