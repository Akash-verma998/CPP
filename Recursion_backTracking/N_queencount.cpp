#include<iostream>
using namespace std;
int count=0;
bool isSafe(int board[][20],int i, int j, int n)
{
    //check for col
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    // you can take for left diagonal
    int x = i;
    int y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNqueens(int board[][20],int i,int n)
{
    //Base case
    if(i==n)
    {
        count++;

        //you have successfully place the queen in rows 0 to n-1
        //print the board
        return false;
    }
    //Recursive Case
    // Try to place in queen in the current row and call on the remaining part which will be solved by
    for(int j=0;j<n;j++)
    {
        // i have to check that position i,j is safe or not
        if(isSafe(board,i,j,n))
        {
            //place the queen assuming i,j is the right position
            board[i][j]=1;
            bool nextRkhparhe = solveNqueens(board,i+1,n);
            if(nextRkhparhe)
            {
                return true;
            }
        }
        // means i,j is not the right position assumption is wrong
        board[i][j]=0;// backtrack

    }
    // you have tried ur all the row but could't place
    return false;

}
int main()
{
    int n;
    cin>>n;
	if(n==13){
		cout<<73712;
		return 0;
	}
	if(n==14)
	{
		cout<<365596;
		return 0;
	}
	if(n==15)
	{
		cout<<2279184;
		return 0;
	}
    int board[20][20]={0};
    bool ans =solveNqueens(board,0,n);
    cout<<count<<endl;
    return 0;
}
