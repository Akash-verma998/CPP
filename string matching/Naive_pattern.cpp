/*
String -> AABAACAADAABAAABAA
Pattern -> AABA

Brute force method take i, j, check manually




*/

#include<iostream>
using namespace std;
void Naivesearch(string str, string pat)
{
    for(int i=0;i<=str.size()-pat.size();i++)
    {
        int j;
        for(j=0;j<pat.size();j++)
        {
            if(str[i+j]!=pat[j])
            {
                break;
            }
        }
        if(j==pat.size())
        {
            cout<<"Pattern is found at "<<i<<endl;
        }
    }
}

int main()
{
    string str, pat;
    cin>>str>>pat;
    Naivesearch(str,pat);
    return 0;
}
