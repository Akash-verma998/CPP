#include<bits/stdc++.h>
using namespace std;
struct comparater{
    bool operator()(int a, int b)
    {
        // if a has higher priority then a should be after b
        // returns the answer of should a appear before b
        if(a<b) return false;
        return false;
    }
};
int main()
{
    priority_queue<int, vector<int>, comparater> pq;
    pq.push(2);
    pq.push(3);
    cout <<pq.top();
    return 0;
}
