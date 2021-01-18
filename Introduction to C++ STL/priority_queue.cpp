#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int a[10] = {5,6,17,18,9,10};
    // inset in a queue
    for(int i=0;i<6;i++)
    {
        pq.push(a[i]);
    }
    // print
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
