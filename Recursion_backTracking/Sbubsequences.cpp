#include<iostream>
using namespace std;
void subsequences(char *s, char *out, int i, int j)
{
    if(s[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<" ";
        return;
    }
    // including element;
    out[j]=s[i];
    subsequences(s,out,i+1,j+1);
    // not including element
    subsequences(s,out,i+1,j);



}
int main()
{
    char s[100];
    cin>>s;
    char out[100];
    subsequences(s,out,0,0);
    return 0;
}
