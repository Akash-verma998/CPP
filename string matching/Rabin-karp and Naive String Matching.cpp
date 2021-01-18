/*
hash(str) = x
hash("babc") = y

str[i,j] then we can easily achieve in o(1) time str[i+1,j+1]
str[0,2] = hash => add the ascii of the character
robin karp algo = rolling hash

str="abcabcabdab"
pat = "abd"
hash(str) = x
1. calculate hash of pat
2. calculate the hash of substring of the given string o to pat.length()-1
o(m) time these two function take
we check hasp(pat) ==  hash(substr)
we use prime number bash it decrease the chance of the
match result
string abcd
suppose for abc  = 97*3^0+98*3^1+99*3^2
and if we want to in bcd then

x-ascii(a) = x - 97 = 98*3^1+99*3^2
divide by prime number  = 98*3^0+99*3^1+100*3^(len(pat)-1)

*/

#include<iostream>
#include<bits/stdc++.h>
#define ll long long int
#define prime 119
using namespace std;
ll createHashValue(string str, int n)
{
    ll result = 0;
    for(int i=0;i<n;i++)
    {
        result+=(ll)(str[i]*(ll)pow(prime,i));
    }
    return result;
}
ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLenght)
{
    ll newHash = oldHash - str[oldIndex];
    newHash/=prime;
    newHash += (ll)(str[newIndex]*(ll)(pow(prime,patLenght-1)));
    return newHash;
}
bool checkEqual(string str1, string str2, int start1,int end1, int start2,int end2)
{
    if(end1-start1 != end2-start2)
    {
        return false;
    }
    while(start1<=end1 && start2<=end2)
    {
        if(str1[start1]!=str2[start2])
        {
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}
int main()
{
    string str="ababcabdab";
    string pat ="abd";
    ll patHash = createHashValue(pat, pat.size());
    ll strHash = createHashValue(str, pat.size());
    for(int i=0;i<=str.size()-pat.size();i++)
    {
        if(patHash==strHash && checkEqual(str, pat,i,i+pat.size()-1,0,pat.size()-1))
        {
            cout<<i<<endl;
            return 0;
        }
        if(i<(str.size()-pat.size()))
        {
            strHash =recalculateHash(str,i,i+pat.size(),strHash,pat.size());
        }
    }
    return 0;
}
