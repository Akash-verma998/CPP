#include<bits/stdc++.h>
using namespace std;
#define MAXN 51
unordered_set <char> S ;
int in_dec[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool check(char Graph[][MAXN],int i,int j,int N, int M, int visited[][MAXN],char p)
{
    if(Graph[i][j]!=p)
        return false;
    if(visited[i][j]==1)
        return true;
    cout<<i<<j<<" ";
    visited[i][j] = 1;
    int new_i,new_j;
    bool got_it=false;
    bool final_re = false;
    for(int p1=0;p1<4;p1++)
    {
        new_i = i+in_dec[p1][0];
        new_j = j+in_dec[p1][1];
        if(new_i>=0 && new_i<N && new_j>=0 && new_j<M)
        {
            if(!visited[new_i][new_j])
            {
                if(Graph[new_i][new_j]==p)
                {
                    got_it = check(Graph,new_i,new_j,N,M,visited,p);
                    if(got_it)
                        final_re=true;
                }
            }
        }
    }
    return final_re;
}

bool solve2(char Graph[][MAXN],char p,int N, int M)
{
    bool ch=false;
    int visited[MAXN][MAXN];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            visited[i][j] = 0;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int s1=i,s2=j;
            if(Graph[i][j]==p)
            {
                bool p1 = check(Graph,i,j,N,M,visited,p);
                if(p1==true)
                    ch=true;
                break;
            }
        }
    }
    return ch;
}

int solve(char board[][MAXN],int n, int m)
{
    int final_res=0;
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           S.insert(board[i][j]);
        }
    }
    unordered_set<char> :: iterator itr;
    for (itr = S.begin(); itr != S.end(); itr++)
    {
        char p = *itr;
        bool res = solve2(board,p,n,m);
        //cout<<res<<" ";
        if(res)
            final_res=1;
    }
    return final_res;
}
int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}





