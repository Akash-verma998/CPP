#include<bits/stdc++.h>
#include<stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("Apple");
    s.push("Mango");
    s.push("Guava");
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
