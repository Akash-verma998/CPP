#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int m=-100;
    for(int i=n1;i<=n2;i++)
    {
        for(int j=n1;j<=n2;j++)
        {
            int p=i^j;
            if (p>m)
            {
                m=p;
            }
        }
    }
    cout<<m<<endl;

}
