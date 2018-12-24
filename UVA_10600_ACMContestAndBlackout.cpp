#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<int,int>  PII;
typedef pair<ll, pair<int, int> > PIII;
typedef long double  ld;
typedef vector<int>  vi;

#define endl         '\n'
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
#define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
#define all(a)       (a).begin(),(a).end()
ll power(ll x, ll y, ll p){ ll res = 1;x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p;y = y>>1;x = (x*x) % p;} return res; } 

// Debug //

#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

// Constants //

const int N = 1e2+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

struct Edge{
	int a, b, w;
	bool operator<(Edge const& other) const{
        return w < other.w;
    }
};

vector<PII> g[N];
int n, m, a, b;
bool vis[N];
vector<Edge> edges;
int d[N][N], cost1, cost2;
vector<Edge> ex_edges;

void pre(){
	cost1 = 0;
	cost2 = 0;
	edges.clear();
	ex_edges.clear();
	for(int i = 1; i <= n; i++)	g[i].clear(),	vis[i] = false;
}

int parent[N];

void make_set(int v){
	parent[v] = v;
}

int find_set(int v){
	if (parent[v]==v)	return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v){
	int a = find_set(u);
	int b = find_set(v);
	if ( a != b )	parent[b] = parent[a];
}

void dfs(int v, int sour, int dest, int w){
	vis[v] = true;
	if ( v == dest ){	d[sour][dest] = w;	d[dest][sour] = w;	return;	}
	for(auto nb : g[v])
		if (!vis[nb.F])
			dfs(nb.F, sour, dest, max(w, nb.S));
}

void solve(){
	
	cin >> n >> m;
	pre();
	Edge x;
	for(int i = 0; i < m; i++)
	{
		cin >> x.a >> x.b >> x.w;
		edges.pb(x);
	}
	for(int i = 1; i <= n; i++)	make_set(i);
	sort(all(edges));	
	cost1 = 0;
	for(auto e : edges)
		if ( find_set(e.a) != find_set(e.b) ){
			cost1 += e.w;
			g[e.a].pb(mp(e.b,e.w));
			g[e.b].pb(mp(e.a,e.w));
			union_sets(e.a, e.b);
		}
		else ex_edges.pb(e);
	//trace(cost1);

	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
		{
			for(int i = 1; i <= n; i++)	vis[i] = false;
			dfs(i, i, j, 0);
		}
	cost2 = INT_MAX;
	for(auto e : ex_edges)
	{
		cost2 = min(cost2, cost1+e.w-d[e.a][e.b]);
	}
	//trace(cost2);
	cout << cost1 << " " << cost2 << endl;
}

int main(){
	
	ios;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	//t = 1;
	while(t--)
		solve();

	return 0;
}
