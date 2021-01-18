#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define w(x)            int x; cin>>x; while(x--)
#define fr(i,a,b)       for(int i = a; i < b; i++)
#define M				1000000007

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void multiply(int a[2][2], int b[2][2])
{
	int x = ((a[0][0] * b[0][0]) + (a[0][1] * b[1][0])) % M;
	int y = ((a[0][0] * b[0][1]) + (a[0][1] * b[1][1])) % M;
	int z = ((a[1][0] * b[0][0]) + (a[1][1] * b[1][0])) % M;
	int w = ((a[1][0] * b[0][1]) + (a[1][1] * b[1][1])) % M;
	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = w;
}

void power(int a[2][2], int b[2][2], int n)
{
	if (n == 1) return;
	while (n > 0)
	{
		if (n & 1)
			multiply(b, a);
		multiply(a, a);
		n >>= 1;
	}
}

int fib_matrix(int n)
{
	int a[2][2] = {{1, 1}, {1, 0}};
	int b[2][2] = {{1, 0}, {0, 1}};
	if (n <= 1) return n;
	power(a, b, n - 1);
	return b[0][0];
}

void build(int *arr, int *tree, int s, int e, int index)
{
	if (s == e)
	{
		tree[index] = arr[s];
		return;
	}
	int mid = (s + e) >> 1;
	build(arr, tree, s, mid, 2 * index);
	build(arr, tree, mid + 1, e, 2 * index + 1);
	tree[index] = __gcd(tree[2 * index], tree[2 * index + 1]) % M;
	return;
}

int query(int *arr, int *tree, int s, int e, int qs, int qe, int index)
{
	if (s > qe or e < qs)
		return 0;
	if (s >= qs and e <= qe)
		return tree[index];
	int mid = (s + e) >> 1;
	int left = query(arr, tree, s, mid, qs, qe, 2 * index);
	int right = query(arr, tree, mid + 1, e, qs, qe, 2 * index + 1);
	return __gcd(left, right) % M;
}

void solve()
{
	int n, q, x;
	cin >> n >> q;
	int arr[n];
	fr(i, 0, n)
	cin >> arr[i];

	int tree[4 * n + 1];
	build(arr, tree, 0, n - 1, 1);
	int L, R;
	fr(i, 0, q)
	{
		cin >> L >> R;
		cout << fib_matrix(query(arr, tree, 0, n - 1, L - 1, R - 1, 1)) << endl;
	}
	return;
}

int32_t main()
{
	c_p_c();
	solve();
	return 0;
}
