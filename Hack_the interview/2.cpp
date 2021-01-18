
#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define pci			pair<char,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;


pair<char,int> construct(pair<char,int> ans[],string &s, int st, int se, int i)
{
    if(st==se) {
        ans[i].first=s[st];
        ans[i].second=1;
        return ans[i];
    }
    int mid = st+(se-st)/2;
    pair<char, int> p1 = construct(ans,s,st,mid,2*i+1);
    pair<char, int> p2 = construct(ans,s,mid+1,se,2*i+2);

    if(p1.first>p2.first) ans[i]=p1;
    else if(p1.first<p2.first) ans[i]=p2;
    else { ans[i].first = p1.first; ans[i].second = p1.second+p2.second; }

    return ans[i];
}

pair<char,int> count(pair<char,int> ans[], int st, int se, int l, int r, int i)
{
    if(l<=st && r>=se)
    {
		return ans[i];
    }
    pair<char,int> p;
    if(l>se || r<st) return p ;

    int mid = st+(se-st)/2;
    pair<char,int> p1 = count(ans,st,mid,l,r, 2*i+1);
    pair<char,int> p2 = count(ans,mid+1,se,l,r, 2*i+2);

    if(p1.first>p2.first) p=p1;
    else if(p1.first<p2.first) p=p2;
    else { p.first = p1.first; p.second = p1.second+p2.second; }

    return p;
}

vector<int> getMaxCharCount(string &s, vector<vector<int>> &queries) {
    int n = s.size();
    int m = ceil(log(n)/log(2));
    m=2*pow(2,m)-1;
    int q = queries.size();
    for(int i=0;i<n;i++) if(isupper(s[i])) s[i]=tolower(s[i]);
    pair<char,int> ans[m];
    construct(ans,s,0,n-1,0);
    vector<int> ret(q,0);
    for(int i=0;i<q;i++)
    {
        pair<char,int> p=count(ans,0,n-1,queries[i][0], queries[i][1],0);
        ret[i]=p.second;
    }

    return ret;
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.

}


void solve(){
	string s;
	int n;
	int q;
	vector<vector<int>> queries;
	cin>>n>>s>>q;
	rep(i,0,q) {
		vi a(2);cin>>a[0]>>a[1];
		queries.pb(a);
	}
	vi ans = getMaxCharCount(s, queries);
	rep(i,0,q) cout<<ans[i]<<endl;

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
