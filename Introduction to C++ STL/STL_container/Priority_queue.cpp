/* push - logn
 pop = O(logn) hight ot tree
 top = O(1)
 head data structure use
*/

#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //priority_queue<int> pq;
    // reverse order
    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        pq.push(no);
    }

    //remove the element
    while(!pq.empty())
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
}
