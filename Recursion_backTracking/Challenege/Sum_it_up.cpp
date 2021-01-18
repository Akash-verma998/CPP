#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int>> ans;
int k;
void subsequences(int *s, vector<int> out, int i, int j,int n)
{
    if(i==n)
    {
    	int sum=0;
    	for(auto e: out)
		{
			sum+=e;
		}
		if(sum==k)
		{
			ans.push_back(out);
		}
        out.clear();
        return;
    }
    // including element;
    subsequences(s,out,i+1,j+1,n);
    out.push_back(s[i]);
    // not including element
    subsequences(s,out,i+1,j,n);
}
bool compare (vector<int> ar1, vector<int> ar2) {
	if (ar1[0]<ar2[0]) return 1;
	if (ar1[0]>ar2[0]) return 0;
	if (ar1[1]<ar2[1]) return 1;
	if (ar1[1]>ar2[1]) return 0;
	return 0;
}

int main()
{
	int n;
	cin>>n;
    int s[100];
    for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	cin>>k;
	sort(s,s+n);
    vector<int> out;
    subsequences(s,out,0,0,n);
    stable_sort(ans.begin(), ans.end(), compare);
    set<vector<int>> st;
    for(auto ele: ans)
	{
		st.insert(ele);
	}
    for(auto ele: st)
	{
		for(auto e: ele)
		{
			cout<<e<<" ";
		}
		cout<<"\n";
	}
    return 0;
}

