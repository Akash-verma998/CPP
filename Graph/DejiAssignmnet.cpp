#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int start;
int n,m;
template<typename T>
class Graph
{
    unordered_map<T,list<pair<T,int>>>m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }

    }
    void printAdj()
    {
        //let try to print adjlist
        for(auto j:m)
        {
            cout<<j.first<<"->";
            for(auto l:j.second)
            {
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }


    }
    void dijsktraSSSP(T src)
    {
        unordered_map<T,int> dist;
        //set all distance to infinite
        for(auto j:m)
        {
            dist[j.first] = INT_MAX;
        }
        //make a set to find node with minimum distance
        set<pair<int,T>> s;// taking int as first params bcz it sort according to first element
        dist[src] = 0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            //find the pair at front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            //iterate over the neighbour of the current node
            for(auto childpair:m[node])
            {
                if(nodeDist+childpair.second<dist[childpair.first])
                {
                    T dest = childpair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                        s.erase(f);
                    dist[dest] = nodeDist+childpair.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }
        }
        for(int i=1;i<=n;i++)
        {
        	if(i==start)
				continue;
			else if(dist[i] == 0)
				cout<<-1<<" ";
			else
			{
				cout<<dist[i]<<" ";
			}
        }
        cout<<endl;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
	{
		Graph<int> g;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x,y,z);
		}
		start;
		cin>>start;
		g.dijsktraSSSP(start);
	}
}

