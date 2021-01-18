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
    bool isCyclicHelper(T node,map<T,bool> &visited,T parent)
    {
        //processing the current node
        visited[node] = true;
        //explore the neighbour
        for(T neighbour : adjList[node])
        {
            //two things can be happen
            //the current node is not visited but it's further brach leads to cycle
            if(!visited[neighbour])
            {
                bool cyclic_detected = isCyclicHelper(neighbour,visited,node);
                if(cyclic_detected)
                    return true;
            }
            else if(neighbour!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCyclicBFS()
    {
        map<T,bool> visited;
        // to check for cycle in each dfs tree
        for(auto i: adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                bool cyclepresent = isCyclicHelper(node,visited,node);
                if(cyclepresent)
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    //g.addEdge(1,2);
    g.print();
    cout<<g.isCyclicBFS();
    return 0;
}

