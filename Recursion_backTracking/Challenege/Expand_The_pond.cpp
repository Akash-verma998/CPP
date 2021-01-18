#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
vector<vector<int>> mat(N,vector<int>(N,0));
vector<vector<int>> grp_id(N,vector<int>(N,0));
vector<int> gr_size(N*N,0);
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool is_safe(int i,int j,int n,int m){
    return (i>=0 && j>=0 && i<n && j<m);
}
void bfs(int x,int y,int n,int m, int col,int &cnt){

      queue<pair<int,int>> q;
      mat[x][y]=0;
      q.push({x,y});
      while(!q.empty()){
          auto p=q.front();
          int i=p.first;
          int j=p.second;
          grp_id[i][j]=col;
          q.pop();
          cnt++;
             for(int k=0;k<4;k++){
               int a=i+dx[k];
               int b=j+dy[k];
                if(is_safe(a,b,n,m) && mat[a][b]==1){
                    mat[a][b]=0;
                    q.push({a,b});
                }
           }
      }
}
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x; cin >> x;
            mat[i][j]=x;
        }
    }
     int col=1;
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(mat[i][j]==1){
                 int cnt=0;
                 bfs(i,j,n,m,col,cnt);
                 gr_size[col]=cnt;
                 col++;
             }
         }
     }
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grp_id[i][j]==0){
				unordered_set<int> s;
				int cnt=1;
				for(int k=0;k<4;k++){
					int a=i+dx[k];
					int b=j+dy[k];
					if(is_safe(a,b,n,m)){
						if(s.find(grp_id[a][b])==s.end()){
						s.insert(grp_id[a][b]);
						cnt+=gr_size[grp_id[a][b]];
						}
                     }
                  }
                  ans=max(ans,cnt);
              }
         }
     }
     cout<<ans<<'\n';
}
int main()
{
    solve();
}
