#include<iostream>
using namespace std;
char keypad[][10]={" "," ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void printKeypad(char *in, char *out, int i, int j)
{
    // Base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<" ";
        return;
    }
    //rec case
    int digit = in[i]-'0';
    if(digit==1|| digit==0)
    {
        printKeypad(in,out,i+1,j);
    }
    else
    {
        for(int k=0;keypad[digit][k]!='\0';k++)
        {
            out[j] = keypad[digit][k];
            printKeypad(in,out,i+1,j+1);
        }

    }
}
int main()
{
    char in[100];
    cin>>in;
    char out[100];
    printKeypad(in,out,0,0);
    return 0;
}
