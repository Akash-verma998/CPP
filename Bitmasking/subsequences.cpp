#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void filterchar(char *a,int no)
{
    int i=0;
    while(no>0)
    {
        (no&1)?cout<<a[i]:cout<<"";
        i++;
        no=no>>1;
    }
    cout<<endl;
}

void generatesSub(char *a)
{
    int n=strlen(a);
    int range = (1<<n)-1;
    for(int i=0;i<=range;i++)
    {
        filterchar(a,i);
    }
}
int main()
{
    int a[100];
    cin>>a;
    generatesSub(a);
    return 0;
}
