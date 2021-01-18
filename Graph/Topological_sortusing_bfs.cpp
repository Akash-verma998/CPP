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

    void dfsTopological_Sort()
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        for(auto i:adjList)
        {
            // i is pair on node and it's list
            T node  = i.first;
            visited[node] = false;
            indegree[node] = 0;
        }
        //Init the Indegree of the node
        for(auto i:adjList)
        {
            T u = i.first;
            for(T v : adjList[u])
            {
                indegree[v]++;
            }
        }
        //find all the node with node degree
        for(auto i: adjList)
        {
            T node = i.first;
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout<<node<<"-->";
            for(T neighbour: adjList[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
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

