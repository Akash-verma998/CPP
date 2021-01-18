#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int k;
void subsequences(int *s,vector<vector<int>> &ans, vector<int> out, int i, int j,int n)
{
    if(i==n)
    {
		ans.push_back(out);
        out.clear();
        return;
    }
    // including element;
    subsequences(s,ans,out,i+1,j+1,n);
    out.push_back(s[i]);
    // not including element
    subsequences(s,ans,out,i+1,j,n);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int s[100];
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		vector<vector<int>> ans;
		vector<int> out;
		subsequences(s,ans,out,0,0,n);
		int check=true;
		for(auto ele: ans)
		{
			int s=0;
			for(auto e: ele)
			{
				s=s+e;
				if(s==0)
				{
					cout<<"Yes\n";
					check=false;
					break;
				}
			}
			if(check==false)
			{
				break;
			}
		}
		if(check)
		{
			cout<<"No\n";
		}

	}
}

