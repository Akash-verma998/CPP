/*
string = "ABAABCXABCXABXA"
pattern = "ABCXABX"

1.no re-computation
2. Reset table - at every index we will be store what is length of longest suffix present till now is also present as a prefix in the pattern


*/
#include<iostream>
#define MAX_N 100005
using namespace std;
int reset[MAX_N];

void KMPpreprocess(string pat)
{
    int i=0, j=1;
    reset[0]=-1;
    while(i<pat.size())
    {
        //check for resetting
        while(j>=0 && pat[i]!=pat[j])
        {
            j=reset[j];
        }
        i++;
        j++;
        reset[i]=j;
    }
}

void KMPsearch(string str, string pat)
{
    KMPpreprocess(pat);
    int i=0,j=0;
    while(i<str.size())
    {
        while(j>=0 && str[i]!=pat[j])
        {
            j=reset[j];
        }
        i++;
        j++;
        if(j==pat.size())
        {
            cout<<"Pattern is found at"<<i-j<<endl;
            j=reset[j];
        }
    }
}
int main()
{
    string str, pat;
    cin>>str>>pat;
    for(int i=0;i<MAX_N;i++)
    {
        reset[i]=-1;
    }
    KMPsearch(str,pat);
    return 0;
}
