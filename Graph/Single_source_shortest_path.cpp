#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<T>> adjList;
public:
    Graph()
    {

    }
    void addEdge(T v, T u, bool bidir=true)
    {
        adjList[v].push_back(u);
        if(bidir)
        {
            adjList[u].push_back(v);
        }
    }
    void print()
    {
        //iterate over the map
        for(auto adj: adjList)
        {
            cout<<adj.first<<"-->";
            for(auto entry: adj.second)
            {
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src)
    {
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        for(auto i: adjList)
        {
            dist[i.first] = INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        parent[src] = src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            //for the neigbours of the current message, find out the nodes which node or not visited
            for(int neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] =dist[node]+1;
                    parent[neighbour] = node;
                }
            }
        }
        //print the distance to all the nodes
        for(auto i:adjList)
        {
            T node = i.first;
            cout<<"Dist of "<<node<<" from "<<src<<" is "<< dist[node]<<endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.print();
    g.bfs(0);
    return 0;
}

