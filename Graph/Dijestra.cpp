#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>>>m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }

    }
    void printAdj()
    {
        //let try to print adjlist
        for(auto j:m)
        {
            cout<<j.first<<"->";
            for(auto l:j.second)
            {
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }


    }
    void dijsktraSSSP(T src)
    {
        unordered_map<T,int> dist;
        //set all distance to infinite
        for(auto j:m)
        {
            dist[j.first] = INT_MAX;
        }
        //make a set to find node with minimum distance
        set<pair<int,T>> s;// taking int as first params bcz it sort according to first element
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            //find the pair at front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //iterate over the neighbour of the current node
            for(auto childpair:m[node])
            {
                if(nodeDist+childpair.second<dist[childpair.first])
                {
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                        s.erase(f);
                    dist[dest] = nodeDist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }
        }
        for(auto d:dist)
        {
            cout<<d.first<<" "<<d.second<<"\n";
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    g.printAdj();
    g.dijsktraSSSP(1);
}
