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
    void dfshelper(T node, map<T,bool> &visited)
    {
        //whenever come to node mark it visited
        visited[node]=true;
        cout<<node<<",";
        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour,visited);
            }
        }


    }
    void dfs(T src)
    {
        map<T,bool> visited;
        int components=1;
        dfshelper(src, visited);
        cout<<endl;
        for(auto i:adjList)
        {
            T city = i.first;
            if(!visited[city])
            {
                dfshelper(city,visited);
                components++;
            }
        }
        cout<<endl;
        cout<<"The current graph have these components: "<<components<<endl;
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
    g.addEdge(6,7);
    g.print();
    g.dfs(0);
    return 0;
}

