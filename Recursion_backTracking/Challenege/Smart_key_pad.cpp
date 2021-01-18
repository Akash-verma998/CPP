#include<bits/stdc++.h>
using namespace std;
char keypad[][10]= {" ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
char searchIn[][20] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak","utkarsh", "divyam", "vidhi", "sparsh", "akku"};
set<string> st;
void printKeypad(char *in, char *out, int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        bool ans=false;
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<strlen(searchIn[i]);j++)
            {
                if(searchIn[i][j]==out[0])
                {
                    int p=j+1;
                    int k=1;
                    while(out[k]==searchIn[i][p])
                    {
                        k++;
                        p++;
                        if(out[k]=='\0')
                        {
                            ans=true;
                            break;
                        }

                    }
                    if(ans==true)
                    {
                        st.insert(searchIn[i]);
                    }
                    ans=false;
                }
            }
        }
        return;
    }
    int digit = in[i]-'0';
    if(digit==0)
    {
    	out[j]=' ';
        printKeypad(in,out,i+1,j+1);
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
    for(auto ele: st)
    {
        cout<<ele<<endl;
    }
    st.clear();
    return 0;
}
