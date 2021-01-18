/*
point on 2d a rubber stretched


first sort on x and then sort on y

point 0,0  1,0  1,0  0,2 1,1 1,2
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long doble
#define F first;
#define S second
#define P pain<int, int>
#define pb push_back
const int N= 100005;
struct point{
	int x,y;
	bool operator < (point &o)
	{
		if(o.x==x) return y<o.y;
		else
			return x<o.x;

	}
	bool operator == (point &o)
	{
		return (x==o.x && y==o.y);

	}
};
bool cw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)>0;
}
bool ccw(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)<0;
}
bool collinear(point a, point b, point c)
{
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)==0;
}
void convex_hull(vector<point> &p)
{
	if(p.size()<=2) return ;

	sort(p.begin(),p.end());
	int i,n=p.size();
	// now p1 is p[0] and p[n-1] is p2
	point p1 = p[0],p2 = p[n-1];
	vector<point> up,down;
	up.pb(p1);
	down.pb(p1);
	// actually p1 is bottom left point and p2 is top right point
	for(i=1;i<n;i++)
	{
		//now i have to check wether my current point is in lower half
		// or uper half
		if(i==n-1 ||!ccw(p1,p[i],p2))
		{
			while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],p[i]))
			{
				up.pop_back();
			}
			up.pb(p[i]);

		}
		if(i==n-1 ||!cw(p1,p[i],p2))
		{
			while(up.size()>=2 && cw(down[down.size()-2],down[down.size()-1],p[i]))
			{
				down.pop_back();
			}
			down.pb(p[i]);
		}

	}
	// up and down vector contains all points including the point p1 and p2 repeated

	p.clear();
	for(i=0;i<up.size();i++)
	{
		p.pb(up[i]);
	}
	for(i=0;i<down.size();i++)
	{
		p.pb(down[i]);
	}
	sort(p.begin(),p.end());
	p.resize(unique(p.begin(),p.end())-p.begin());

}
void solve()
{
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	vector<point> p(n);
	for(i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	convex_hull(p);
	//p contains all the point
	for(auto x:p)
	{
		cout<<x.x<<" "<<x.y<<"\n";
	}

}
int32_t main()
{
	solve();
}
