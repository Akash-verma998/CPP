#include<iostream>
#include<cstring>
using namespace std;
char input[1000],output[1000];
void findLargestUniqueSubstring(char input[], char output[]){
    int i,j;
    int n=strlen(input);
    string s1,maxs;
    s1=input[0];
    maxs = input[0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<s1.length();j++)
        {
            if(s1[j]==input[i])
                break;
        }
        if(j==s1.length())
            s1=s1+input[i];
        else
            s1=s1.substr(j+1)+input[i];
        if(s1.length()>maxs.length())
                maxs=s1;
    }
    for(i=0;i<maxs.length();i++)
    {
        output[i]=maxs[i];
    }
}
int main()
{
    cin>>input;
    findLargestUniqueSubstring(input,output);
    cout<<output;
}
