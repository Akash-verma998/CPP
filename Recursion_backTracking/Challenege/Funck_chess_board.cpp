#include<bits/stdc++.h>
using namespace std;
int grid[11][11];
int ma = -99999;
int data[8][8] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
void go(int grid[][11],int n,int x,int y,int count)
{
	if(x>=n || x<0 || y>=n || y<0 || grid[x][y]==0)
		return ;
	ma =  max(ma,count);
	for(int i=0;i<8;i++)
	{
		int xx = x + data[i][0];
		int yy = y + data[i][1];
		if(grid[xx][yy]==1 && xx>=0 && xx<=n-1 && yy>=0 && yy<=n-1)
		{
			grid[x][y]=0;
			go(grid,n,xx,yy,count+1);
			grid[x][y]=1;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>grid[i][j];
			if(grid[i][j])
			{
				sum+=1;
			}
		}
	}
	go(grid,n,0,0,1);
	cout<<sum-ma<<endl;
}
