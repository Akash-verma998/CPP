#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int t;
    long long int w,h,n;
    cin>>t;
    long long int x[40010],y[40100];
    while(t--)
    {
        cin>>w>>h>>n;
        if(n==0)
        {
            cout<<w*h<<endl;
            continue;
        }
        for(long long int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        //sorting
        sort(x,x+n);
        sort(y,y+n);
        long long int dx = x[0]-1;
        long long int dy = y[0]-1;
        for(long long int i=0;i<n;i++)
        {
            dx = max(dx,x[i]-x[i-1]-1);
            dy = max(dy,y[i]-y[i-1]-1);
        }
        dx = max(dx,w-x[n-1]);
        dy = max(dy,h-y[n-1]);
        long long int  p = dx*dy;
        cout<<p<<endl;
    }
    return 0;
}
