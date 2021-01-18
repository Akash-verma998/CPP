#include<iostream>
#include<cmath>
using namespace std;
bool check(int board[][9],int row,int col,int val)
{
    for(int k=0;k<9;k++)
    {
        if(board[row][k]==val)
            return false;
        if(board[k][col]==val)
            return false;
    }
    int rn = sqrt(9);
    int TopRowIndice = int((row/rn)*rn);
    int TopColIndice = int((col/rn)*rn);
    for(int c=TopRowIndice;c<TopRowIndice+3;c++)
    {
        for(int d=TopColIndice;d<TopColIndice+3;d++)
        {
            if(board[c][d]==val)
            {
                return false;
            }
        }
    }
    return true;
}
bool helper(int board[][9],int row,int col)
{
    if(row==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        return true;

    }
    if(col==9)
        return helper(board,row+1,0);
    if(board[row][col]!=0)
    {
        return helper(board,row,col+1);
    }
    for(int k=1;k<=9;k++)
    {
        if(check(board,row,col,k))
        {
            board[row][col]=k;
            if(helper(board,row,col+1))
                return true;
        }
        board[row][col]=0;
    }
    return false;
}
int main()
{
    int board[9][9]=
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
    helper(board,0,0);
}
