#include<iostream>
using namespace std;
int birthday_paradox(float p)
{
    float c_p=1;
    int i=0;
    float num = 365;
    float denum = 365;
    if (p==1)
    {
        return 366;
    }
    while(1)
    {
        c_p*=num/denum;
        if(c_p<=(1-p))
        {
            return i+1;
        }
        num--;
        i++;
    }
}
int main()
{
    float p;
    cin>>p;
    int res=birthday_paradox(p);
    cout<<res;
    return 0;
}
