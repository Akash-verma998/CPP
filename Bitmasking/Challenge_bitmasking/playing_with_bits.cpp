#include<iostream>
using namespace std;
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {

        cin>>a>>b;
        int coun=0;
        for(int i=a;i<=b;i++)
        {
            int c=i;
            while(c)
            {
               coun++;
               c=c&(c-1);
            }
        }
        cout<<coun<<"\n";

    }
    return 0;

}
