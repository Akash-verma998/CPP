#include<iostream>
#include<cmath>
using namespace std;
bool canput(int mat[][9],int i, int j ,int n, int number)
{
    // row column check
    for(int x=0;x<n;x++)
    {
        if(mat[x][j]==number)
        {
            return false;
        }
        if(mat[i][x]==number){
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = int((i/rn)*rn);
    int sy = int((j/rn)*rn);
    // box check
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(mat[x][y]==number)
            {
                return false;
            }
        }
    }
    return true;

}
bool solveSuduko(int mat[][9], int i, int j, int n)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;
    }
    // coz row end
    if(j==n)
    {
       return solveSuduko(mat,i+1,0,n);
    }
    // if already filled
    if(mat[i][j]!=0)
    {
        return solveSuduko(mat,i,j+1,n);
    }
    //rec case
    // fill the current cell with possible number
    for(int number=1;number<=n;number++)
    {
        if(canput(mat,i,j,n,number))
        {
            mat[i][j]=number;
            bool coldbesolve = solveSuduko(mat,i,j+1,n);
            if(coldbesolve==true)
            {
                return true;
            }
        }
        mat[i][j]=0;
    }
    return false;
}
int main()
{
    int mat[9][9]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,0}
    };
    int n=9;
    bool ans = solveSuduko(mat,0,0,n);
    return 0;
}
