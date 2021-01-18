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
    bool isCyclicBFS(T src)
    {
        map<T,bool> visited;
        map<T,int> parent;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        parent[src] = src;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            //Iterate over the neighbour of that node leaving parent
            for(T neighbour : adjList[node])
            {
                if(visited[node]==true && parent[node]!=neighbour)
                {
                    return true;
                }
                else if(!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return false;

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
    cout<<g.isCyclicBFS(0);
    return 0;
}

