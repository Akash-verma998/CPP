#include<iostream>
using namespace std;
#include<cstring>
int main()
{
    /*
    char input[100];
    cin>>input;
    int len =strlen(input);
    cout<<len<<endl;
    */

    /*
    char s1[100],s2[100];
    cin>>s1;
    cin>>s2;
    if(strcmp(s1,s2)==0)
    {
        cout<<"true";
    }
    else{
        cout<<"False";
    }
    */
    char s1[100],s2[100];
    cin>>s1;
//    strcpy(s2,s1);
//    cout<<s2;
    strncpy(s2,s1,3);
    cout<<s2;

}
