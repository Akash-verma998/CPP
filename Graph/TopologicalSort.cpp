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
    void dfshelper(T node, map<T,bool> &visited,list<T> &ordering)
    {
        //whenever come to node mark it visited
        visited[node]=true;
        // will call dfs on the unvisited neighbours of then current node
        for(T neighbour:adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour,visited,ordering);
            }
        }
        //Add 1 line for TS
        //all this point , all the children of current node have been visited
        // so we can add current node to the list
        ordering.push_front(node);

    }
    void dfsTopological_Sort()
    {
        map<T,bool> visited;
        list<T> ordering;
        for(auto i: adjList)
        {
            // i is pair (node, list of node)
            T node = i.first;
            if(!visited[node])
            {
                dfshelper(node, visited, ordering);
            }
        }
        for(T ele:ordering)
            cout<<ele<<"->>";
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.print();
    g.dfsTopological_Sort();
    return 0;
}

