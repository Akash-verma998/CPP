
#include<iostream>
using namespace std;
bool check = true;
bool ratInmaze(char maze[][100],int soln[][100],int i, int j, int m ,int n)
{
    if(i==m&&j==n && check)
    {
    	check = false;
        soln[m][n]=1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        return true;
    }
    if(j>n||i>m)
    {
        return false;
    }
    if(maze[i][j]=='X')
    {
        return false;
    }
    soln[i][j]=1;
    bool rightward = ratInmaze(maze,soln,i,j+1,m,n);
    bool leftward = ratInmaze(maze, soln,i+1,j,m,n);
    soln[i][j]=0;
    if(rightward||leftward)
    {
        return true;
    }
    return false;
}
int main()
{
    char maze[100][100];
    int soln[100][100]={0};
    int n, m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>maze[i][j];
		}
	}
    bool ans =  ratInmaze(maze, soln, 0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"-1";
    }
    return 0;
}
