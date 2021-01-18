#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool compare (pair<long long int,long long int> p1, pair<long long int,long long int>p2)
{
    return p1.first>p2.first;
}
int main()
{
    long long int n,t,x,d,f,D,F,prev=0;
    cin>>t;
    while(t--)
    {
        int flag =0;
        long long int ans=0;
        vector<pair<long long int,long long int>> v;
        priority_queue<long long int> pq;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>d>>f;
            v.push_back(make_pair(d,f));
        }
        //logic
        sort(v.begin(),v.end(),compare);
        cin>>D>>F;
        //update the distance of the fuel station to the truck
        for(int i=0;i<n;i++)
        {
            v[i].first = D - (v[i].first);
        }
        //prev denotes the prev city we have visited
        prev=0;
        x=0; //current city
        while(x<n)
        {
            // if we have enough fuel to go to next city
            if(F>=(v[x].first-prev))
            {
                F=F-(v[x].first-prev);
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else
            {
                // check if you have some fuelling station visited int the priority queue
                if(pq.empty())
                {
                    flag =1;
                    break;
                }
                //other wise refuel the truck with fuel stations with higher capacity
                F+=pq.top();
                // Remove that station from priority queue;
                pq.pop();
                ans = ans +1;
                continue;
            }
            x++;
        }
        // actually travelled through n fuel stations
        // what is left you have reach the town from the last fuel
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        D= D-v[n-1].first;
        if(F>=D)
        {
            cout<<ans<<endl;
            continue;
        }
        //otherwise
        while(F<D)
        {
            if(pq.empty())
            {
                flag=1;
                break;
            }
            F+=pq.top();
            pq.pop();
            ans=ans+1;
        }
        if(flag==1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}
