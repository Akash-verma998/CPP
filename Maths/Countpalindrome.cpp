#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000];


int countPalindromeSubstrings(char s[]) {
    int count=0;
	int i,n,j,k;
	n=strlen(s);
	string s2="",s1,p;
	for(i=0;i<n;i++)
    {
        s2+=s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
        {
            s1=s2.substr(i, len);
            if(s1.length()==1)
            {
                count++;
                continue;
            }
            else{
            p=s1;
            reverse(s1.begin(), s1.end());
            if (p==s1)
            {
                count++;
            }
            }
        }
    }
    return count;
}

int main()
{
    cin>>s;
    int p;
    p=countPalindromeSubstrings(s);
    cout<<p;
}

