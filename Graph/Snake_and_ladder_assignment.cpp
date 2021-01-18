
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include <climits>
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
        return dist[dest];
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Graph<int> g;
		int board[101]={0};
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int p,q;
			cin>>p>>q;
			board[p] = q-p;
		}
		int m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			int p,q;
			cin>>p>>q;
			board[p] = (q-p);
		}
		//let first construct the graph add pairs u,v
		for(int u=0;u<=100;u++)
		{
			//at every node u can throw a dice
			for(int dice=1;dice<=6;dice++)
			{
				int v = u + dice + board[u+dice];
				g.addEdge(u,v,false);
			}

		}
		if (g.bfs(0,100)==2147483647)
		{
			cout<<-1<<endl;
			continue;
		}
		cout<<g.bfs(0,100)<<endl;;
	}
    return 0;
}


