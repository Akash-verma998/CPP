#include<iostream>
using namespace std;
bool ratInmaze(char maze[][10],int soln[][10],int i, int j, int m ,int n)
{
    if(i==m&&j==n)
    {
        soln[m][n]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
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
    char maze[10][10]={
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    int soln[10][10]={0};
    int m=4,n=4;
    bool ans =  ratInmaze(maze, soln, 0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"Path does't exist\n";
    }
    return 0;
}
