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
    bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack)
    {
        //processing the current node
        visited[node] = true;
        inStack[node] = true;
        //explore the neighbour
        for(T neighbour : adjList[node])
        {
            //two things can be happen
            //the current node is not visited but it's further brach leads to cycle
            if(!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack)||inStack[neighbour])
            {
                return true;
            }
        }
        //going to pop out that node from the stack
        inStack[node] = false;
        return false;

    }
    bool isCyclicBFS()
    {
        map<T,bool> visited;
        map<T,bool> inStack;
        // to check for cycle in each dfs tree
        for(auto i: adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                bool cyclepresent = isCyclicHelper(node,visited,inStack);
                if(cyclepresent)
                    return true;
                return false;

            }
        }

    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0,1,false);
    g.addEdge(0,2,false);
    g.addEdge(2,4,false);
    g.addEdge(2,3,false);
    //g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);
    g.print();
    cout<<g.isCyclicBFS();
    return 0;
}

