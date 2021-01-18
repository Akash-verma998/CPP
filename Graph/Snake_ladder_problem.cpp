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
    int bfs(T src, T dest)
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
        T temp = dest;
        while(temp!=src)
        {
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;

        //print the distance to all the nodes
//        for(auto i:adjList)
//        {
//            T node = i.first;
//            cout<<"Dist of "<<node<<" is "<< dist[node]<<endl;
//        }

        return dist[dest];
    }
};
int main()
{
    Graph<int> g;
    int board[100]={0};

    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    //let first construct the graph add pairs u,v
    for(int u=0;u<=36;u++)
    {
        //at every node u can throw a dice
        for(int dice=1;dice<=6;dice++)
        {
            int v = u + dice + board[u+dice];
            g.addEdge(u,v,false);
        }

    }
    cout<<"the shortest is "<<g.bfs(0,36);
    return 0;
}


