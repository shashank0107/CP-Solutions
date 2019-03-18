#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<ll,ll>                 PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;
typedef vector<pair<int, int> >     vii;

#define endl         '\n'
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
#define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
#define all(a)       (a).begin(),(a).end()
#define fr(i,a,b)    for(int i=a;i<=b;i++)
#define lp(i,a)      for(int i=0;i< a;i++)

// Debug //

#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

// Constants //

const int N = 1024000+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

int a[N], tree[4*N], lazy[4*N], m, t, n;
string st;

void build(int start, int end, int node){
	if (start == end){
		tree[node] = a[start];
		return;
	}
	int mid = (start+end)/2;
	build(start, mid, 2*node);
	build(mid+1, end, 2*node+1);
	tree[node] = tree[2*node] + tree[2*node+1];
}

void conv(int node){
	if (lazy[node] == 0)	lazy[node] = 3;
	else if (lazy[node] == 1)	lazy[node] = 2;
	else if (lazy[node] == 2)	lazy[node] = 1;
	else if (lazy[node] == 3)	lazy[node] = 0;
	else assert(false);
}

void update(int start, int end, int node, int l, int r, int v){
	if (lazy[node] != 0)
	{
		if (lazy[node] == 1)
		{
			tree[node] = (end-start+1);
			if (start != end){
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node]; 
			}
		}
		else if (lazy[node] == 2)
		{
			tree[node] = 0;
			if (start != end){
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node]; 
			}
		}
		else if (lazy[node] == 3)
		{
			tree[node] = (end-start+1) - tree[node];
			if (start != end){
				conv(2*node);
				conv(2*node+1);
			}
		}
		else assert(false);

		lazy[node] = 0;
	}
	if (r < start || end < l)	return;
	if (l <= start && end <= r)
	{
		if (v== 1)
		{
			tree[node] = (end-start+1);
			if (start != end){
				lazy[2*node] = 1;
				lazy[2*node+1] = 1; 
			}
		}
		else if (v == 2)
		{
			tree[node] = 0;
			if (start != end){
				lazy[2*node] = 2;
				lazy[2*node+1] = 2; 
			}
		}
		else if (v == 3)
		{
			tree[node] = (end-start+1) - tree[node];
			if (start != end){
				conv(2*node);
				conv(2*node+1);
			}
		}
		return;
	}
	int mid = (start+end)/2;
	update(start, mid, 2*node, l, r, v);
	update(mid+1, end, 2*node+1, l, r, v);
	tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int start, int end, int node, int l, int r){
	if (lazy[node] != 0)
	{
		if (lazy[node] == 1)
		{
			tree[node] = (end-start+1);
			if (start != end){
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node]; 
			}
		}
		else if (lazy[node] == 2)
		{
			tree[node] = 0;
			if (start != end){
				lazy[2*node] = lazy[node];
				lazy[2*node+1] = lazy[node]; 
			}
		}
		else if (lazy[node] == 3)
		{
			tree[node] = (end-start+1) - tree[node];
			if (start != end){
				conv(2*node);
				conv(2*node+1);
			}
		}
		else assert(false);

		lazy[node] = 0;
	}
	if (r < start || end < l)	return 0;
	if (l <= start && end <= r)	return tree[node];
	int mid = (start+end)/2;
	int p1 = query(start, mid, 2*node, l, r);
	int p2 = query(mid+1, end, 2*node+1, l, r);
	return p1+p2;
}
int q, l, r;
char ch;
void solve(){
    
    memset(a, 0, sizeof a), memset(tree, 0, sizeof tree), memset(lazy, 0, sizeof lazy);
    cin >> m;
    int c = 0, qn = 1;
    lp(i, m)
    {
    	cin >> t >> st;
    	lp(k, t)
    	{
    		for(auto i : st)	a[c++] = i-'0';
    	}
    }
    n = c;
    //lp(i, n)	cout << a[i] << " ";	cout << endl;

    build(0, n-1, 1);
    cin >> q;
    lp(i, q){
    	cin >> ch >> l >> r;
    	if (ch == 'F')		update(0, n-1, 1, l, r, 1);
    	else if (ch == 'E')	update(0, n-1, 1, l, r, 2);
    	else if (ch == 'I')	update(0, n-1, 1, l, r, 3);
		else if (ch == 'S')
		{
			cout << "Q" << qn++ << ": " << query(0, n-1, 1, l, r) << endl;
		}
		else assert(false);
    }

}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fr(i, 1, t){
    	cout << "Case " << i << ":" << endl;
    	solve();
    }
    return 0;
}
