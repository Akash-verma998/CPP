/*        Minimum cut problem


     in a flow network , and s-t cut is a cut that require's the source & the sink to be in dofferent subsets & it consists of all edges gping from source side to the sink side

     sum of the capacity of each edge is the cut

     1. Run the for algorithm & calculate the final resudal graph
     2. find the set of vertes thta reachable form the source
     3. All the edges which are non reachable vertex & from reachable vertes are min cut edge


         Terminologies Regarding  Network flow
         Capacity: flow is the exact amount of material flowing through edge,
         capacity is the maximum amount of material that can flow through a edge

         Residual capacity: Total capacity - flow of material

         Augmented path : A path form source to sink such that residual capacity on every edge is greater than
         zero

         A-2->B-4->C-0->D


         Ford fulkerson Algorithm

         1. so flow can not be greater than max capacity of edge
         2. for two vertex  A<--->B the amount of flow going ot inside at every vertex should be equal to flow going ot outside
         (excluding source & sink)

         3. A-10->B-2->C-4->D---> Augmented path
         4. Non zero backward edge & a non full forward edge

         Algorithm:

         1.Setup your directed residual graph with edge capacity
         original graph.
         2. max_flow = 0
         3. while( there exist any augmented path form source -> sink)
            1. find f the minimum edge weight along the current path
            2. Decrease the capacity of all the forward edge by f
            3. Increase the capacity of all the backward edge by f
            4. max_flow +=f

            print(max_flow)


    see the screen shot

    ford fulkerson+ dfs =  kard algo

5 7
0 2 100
0 3 50
2 3 50
2 4 50
2 1 50
3 4 100
4 1 125



*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool bfs(int **residualCapacity , int source, int sink, int n, int *parent)
{
    bool visited[n];
    memset(visited,0,sizeof(visited));
    queue<int> que;
    visited[source]=true;
    que.push(source);
    bool foundAugmentedPath = false;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v=0;v<n;v++)
        {
            if((visited[v]==false) && (residualCapacity[u][v]>0))
            {
                parent[v]=u;
                visited[v]=true;
                que.push(v);
                if(v==sink)
                {
                    foundAugmentedPath=true;
                    break;
                }
            }
        }
    }
    return foundAugmentedPath;
}
void printAugpath(vector<vector<int>> augmentsPaths)
{
    for(int i=0;i<augmentsPaths.size();i++)
    {
        for(int j=0;j<augmentsPaths[i].size();j++)
        {
            cout<<augmentsPaths[i][j]<<",";
        }
        cout<<endl;
    }
}
int maxFlow(int **capacity , int source, int sink, int v)
{
    int **residualCapacity = new int*[v];
    for(int i=0;i<v;i++)
    {
        residualCapacity[i]=new int[v];
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            residualCapacity[i][j]=capacity[i][j];
        }
    }
    int *parent  =new int[1000];
    vector<vector<int>> augmentedpaths;
    int maxflow =0;
    while(bfs(residualCapacity,source,sink,v, parent))
    {
        vector<int> currentAugmentedpath;
        int flow = INT_MAX;
        int v  = sink;
        while(v!=source)
        {
            currentAugmentedpath.push_back(v);
            int u =parent[v];
            if(flow>residualCapacity[u][v])
            {
                flow = residualCapacity[u][v];
            }
            v=u;
        }
        currentAugmentedpath.push_back(source);
        std::reverse(currentAugmentedpath.begin(),currentAugmentedpath.end());
        augmentedpaths.push_back(currentAugmentedpath);
        maxflow += flow;
        v=sink;
        while(v!=source)
        {
            int u  =parent[v];
            residualCapacity[u][v]-=flow;
            residualCapacity[v][u]+=flow;
            v=u;
        }
    }
    printAugpath(augmentedpaths);
    return maxflow;
}
int main()
{
    int v, e;
    cin>>v>>e;
    int **capacity  = new int*[v];
    for(int i=0;i<v;i++)
    {
        capacity[i] = new int[v];
        for(int j=0;j<v;j++)
            capacity[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        capacity[u][v] = c;
    }
    cout<<maxFlow(capacity,0,1,v);
    return 0;
}
