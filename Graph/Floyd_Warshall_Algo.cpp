/*
Floyd-Warshall Algorithms
1. used to find shortest path between all pairs of vertices.(in directed as well as undirected graph)
2. Will work even if negative edges present.
3. Will also able to detect negative cycles.
Time complexity- O(V^3)
Space complexity - O(V^2)
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> all_pair_shortest_path(int n, vector<vector<pair<int,int>>> &adj)
{
	vector<vector<int>> dist(n+1,vector<int>(n+1,2e9));
	for(int i=1;i<=n;i++)
	{
		dist[i][i]=0;
		for(pair<int,int> ed : adj[i])
		{
			int nb = ed.first;
			int w = ed.second;
			dist[i][nb] = w;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	return dist;
}
int main()
{

}
