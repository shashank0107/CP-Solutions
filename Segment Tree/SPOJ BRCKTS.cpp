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

const int N = 3e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/
struct node{
	int c, o;
};

node tree[4*N];
string s;
int n, m, op;

void build(int start, int end, int nd){
	if (start == end){
		if (s[start] == ')')	tree[nd].c = 1, tree[nd].o = 0;
		else					tree[nd].o = 1, tree[nd].c = 0;
		return;
	}
	int mid = (start+end)/2;
	build(start, mid, 2*nd);
	build(mid+1, end, 2*nd+1);
	tree[nd].o = tree[2*nd+1].o + max(tree[2*nd].o - tree[2*nd+1].c, 0);
	tree[nd].c = tree[2*nd].c + max(tree[2*nd+1].c - tree[2*nd].o, 0);
}

void update(int start, int end, int nd, int idx){
	if (start == end){
		tree[nd].c = 1 - tree[nd].c;
		tree[nd].o = 1 - tree[nd].o;
		return;
	}
	int mid = (start+end)/2;
	if (idx <= mid)	update(start, mid, 2*nd, idx);
	else			update(mid+1, end, 2*nd+1, idx);
	tree[nd].o = tree[2*nd+1].o + max(tree[2*nd].o - tree[2*nd+1].c, 0);
	tree[nd].c = tree[2*nd].c + max(tree[2*nd+1].c - tree[2*nd].o, 0);
}

void solve(){
    
	cin >> n >> s >> m;
	build(0, n-1, 1);
	//lp(i, 4*n)	trace3(i, tree[i].o, tree[i].c);
	lp(i, m)
	{
		cin >> op;
		if (op == 0){
			cout << ((tree[1].c == 0 && tree[1].o == 0) ? "YES" : "NO") << endl;
		}
		else
		{
			op--;
			update(0, n-1, 1, op);
		}
		//lp(i, 4*n)	trace3(i, tree[i].o, tree[i].c);
	}    
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    //cin >> t;
    t = 10;
    fr(i, 1, t){
    	cout << "Test " << i << ":" << endl;
    	solve();
    }
    return 0;
}
