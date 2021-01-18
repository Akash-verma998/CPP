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
        map<T,bool> visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            //for the neigbours of the current message, find out the nodes which node or not visited
            for(int neighbour: adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }
};
int main()
{
    /*
    Graph<string> g;
    g.addEdge("putin","modi",false);
    g.addEdge("putin","trump",false);
    g.addEdge("putin","pop",false);
    g.addEdge("modi","trump",true);
    g.addEdge("modi","yogi",true);
    g.addEdge("yogi","prabhu",false);
    g.addEdge("prabhu","modi",false);
    g.print();
    */
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
