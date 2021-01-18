/*
#include<iostream>
using namespace std;
bool isSafe(int board[][10],int i, int j, int n)
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
int ans;
int count=0;
bool p=false;
bool solveNqueens(int board[][10],int i,int n)
{

    //Base case
    if(i==n)
    {
        ans++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<"Q\t";
                }
                else
                {
                    cout<<"-\t";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";

        //you have successfully place the queen in rows 0 to n-1
        //print the board
        p=true;
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
    int board[10][10]={0};
    bool s=solveNqueens(board,0,n);
    if(ans==0)
        cout<<"Not Possible"<<endl;
    cout<<endl;
    //cout<<ans<<endl;
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
bool set=true;
bool isSafe(int board[][10],int i,int j,int n)
{
	//check for the above coloum
	for(int row=0;row<i;row++)
	{
		if(board[row][j]==1)
		{
			return false;
		}
	}
	//check for left above diagnol
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
	//check for right above daignol
	x=i;
	y=j;
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
bool solveNqueen(int board[][10],int i,int n)
{
	//base case
	if(i==n)
	{
	    set=false;	//print the board
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				if(board[x][y]==1)
				{
					cout<<"Q\t";
				}
				else
				{
					cout<<"-\t";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}
	//recursive case
	for(int j=0;j<n;j++)
	{
		//check if board[i][j] is safe to place
		if(isSafe(board,i,j,n))
		{
			board[i][j]=1;
			bool nextQueenRakhPaye = solveNqueen(board,i+1,n);
			if(nextQueenRakhPaye)
			{
				return true;
			}
			board[i][j]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[10][10]={0};
	solveNqueen(board,0,n);
	if(set)
	{
	    cout<<"Not Possible"<<endl;
	}
	return 0;
}
*/

