

int main()
{
	 int t;
	 cin>>t;
	 while(t--)
	 {
	 	cin>>n>>m;
	 	int mx = 0;
	 	for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>arr[i][j];
				mx = max(mx,arr[i][j]);
			}
		}
		add_edges();
		spl.clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(arr[i][j]==mx)
				{
					spl.push_back({i,j})
				}
			}
		}
		cout<<get_ans()<<"\n";
	 }
}
