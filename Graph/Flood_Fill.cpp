#include<iostream>
#include<fstream>
#include<windows.h>

/*
The different color codes are

0   BLACK
1   BLUE
2   GREEN
3   CYAN
4   RED
5   MAGENTA
6   BROWN
7   LIGHTGRAY
8   DARKGRAY
9   LIGHTBLUE
10  LIGHTGREEN
11  LIGHTCYAN
12  LIGHTRED
13  LIGHTMAGENTA
14  YELLOW
15  WHITE
*/
using namespace std;
int R,C;
char mat[50][50];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
void printmat(char mat[][50])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mat[i][j]=='r')
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            else if(mat[i][j]=='.')
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            else if(mat[i][j]=='#')
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
            cout<<mat[i][j];
        }
        cout<<endl;
    }
}
void flood_fill(char mat[][50],int i, int j, char ch,char color)
{


    //Base case
    if(i<0||j<0||i>=R||j>=C)
    {
        return ;
    }
    //boundary condition
    if(mat[i][j]!=ch)
    {
        return ;
    }
    //Recursive call
    mat[i][j] = color;
    for(int k=0;k<4;k++)
    {
        flood_fill(mat,i+dx[k],j+dy[k],ch,color);
    }
}
int main()
{
    ifstream file;
    string t, q, filename;
    char word;
    filename = "test.txt";
    file.open(filename.c_str());
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    cin>>R>>C;
    int i=0;
    int j=0;
    while(file>>word)
    {
        mat[i][j]=word;
        j++;
        if(j==C){
            i++;
            j=0;
        }
    }
    printmat(mat);
    flood_fill(mat,8,13,'.','r');
    printmat(mat);
}
