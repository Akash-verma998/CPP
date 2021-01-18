/*
time in , time out concept
                                       1
									  / \
									 2   3
								   / | \  \
                                  4  5 6   7
										  / \
										 8   9

           index 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17

1st type initial at 1-> 1 2 4 2 5 2 6 2 1 3  7   8  7  9  7  3  1
2nd type euler          1 2 4 4 5 5 6 6 2  3 7   8  8  9  9  7  3  1

first occurrence - enter time
last occurrence  - exit time
					index   time in         time out


                       1       1               18
                       2       2			   9
                       3       10              17
                       4       3               4
                       5       5               6
                       6       7               8
                       7       11              16
                       8       12              13
                       9       14              15


(2*n-2) + 1 = index  = 2* 9-1 = 17 index

question
x in ancestor of y or not?

y is in subtree of x or not?

x comes in path from y to root?

whether

9
1 2
2 4
2 5
2 6
1 3
3 7
7 8
7 9

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1000005, M=22;
vector<int> gr[N];
int tin[N], tout[N] ,timer=0;
//whether x in ancestor of y or not
bool is_ancestor(int x, int y)
{
	return tin[x]<=tin[y] && tout[x]>=tout[y];
}
void euler_tour_1(int cur, int par)
{
	cout<<cur<<" ";
	for(auto x: gr[cur])
	{
		if(x!=par)
		{
			euler_tour_1(x,cur);
			cout<<cur<<" ";
		}
	}
	return ;
}
void euler_tour_2(int cur, int par)
{
	cout<<cur<<" ";
	for(auto x: gr[cur])
	{
		if(x!=par)
		{
			euler_tour_2(x,cur);
		}
	}
	cout<<cur<<" ";
	return ;
}
void euler_tour_3(int cur, int par)
{
	//cout<<cur<<" ";
	tin[cur] = ++timer;
	for(auto x: gr[cur])
	{
		if(x!=par)
		{
			euler_tour_3(x,cur);
		}
	}
	tout[cur] = timer;
	return ;
}
int main()
{
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
//	euler_tour_1(1,0);
//	cout<<"\n";
//	euler_tour_2(1,0);
//	cout<<"\n";
	timer=0;
	euler_tour_3(1,0);
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<tin[i]<<" "<<tout[i]<<endl;
	}
	if(is_ancestor(1,7))
	{
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}





















