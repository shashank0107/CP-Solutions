#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<int,ll>  PII;
typedef pair<ll, pair<int, int> > PIII;
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
#define M_PI         3.14159265358979323846264338327950288
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
int n, e;
vector<PII> g[N];
vector<PIII> edges;
bool vis[N];
ll c[N][N];

int parent[N];
int size[N];

void make_set(int i){
	parent[i] = i;
	size[i] = 1;
}

int find_set(int i){
	if (i == parent[i])	return i;
	return parent[i] = find_set(parent[i]);
}

void union_set(int i, int j){
	int a = find_set(i);
	int b = find_set(j);
	if (a != b){
		if (size[a] < size[b])	swap(a, b);
		parent[b] = a;
		size[a]+=size[b];
	}
}

void pre(){
	for(int i = 1; i <= n; i++)	g[i].clear(), make_set(i);
	edges.resize(e);
	memset(c, 0, sizeof c);
	memset(vis, 0, sizeof vis);
}


ll dfs(int v, int b){

	vis[v] = true;
	if (v == b){	return 0;	}
	
	int ret = INT_MAX;

	for(auto nb : g[v]){
		if (!vis[nb.F]){
			int rnb = dfs(nb.F, b);
			//trace3(v, nb.F, rnb);
			if (rnb != -1){	
				ret = max(nb.S, (ll)rnb);
				return ret;
			}
		}
	}
	return -1;

}

ll solve(){
	
	cin >> n >> e;
	pre();
	for(int i = 0; i < e; i++)	
		cin >> edges[i].S.F >> edges[i].S.S >> edges[i].F;

	sort(all(edges));
	vector<PIII> left;
	ll cost = 0;

	for(auto i :edges){
		if (find_set(i.S.F) != find_set(i.S.S)){
			//trace3(i.S.F, i.S.S, i.F);
			union_set(i.S.F, i.S.S);
			cost+=i.F;
			g[i.S.F].pb(mp(i.S.S, i.F));
			g[i.S.S].pb(mp(i.S.F, i.F));
			c[i.S.F][i.S.S] = i.F;
			c[i.S.S][i.S.F] = i.F; 
		}
		else
			left.pb(i);
	}
	//exit(1);
	ll nxt_min = INT_MAX;

	for(auto i : left){
		//trace3(i.F, i.S.F, i.S.S);
		
		memset(vis, false, sizeof vis);

		int a = i.S.F, b = i.S.S;
		ll cx = dfs(a, b);
		if (cx == INF)	cx = 0;
		//trace3(a, b, cx);

		nxt_min = min(cost-cx+i.F, nxt_min);
	}
	bool valid = true;
	int p = find_set(1);
	for(int i = 2; i <= n; i++)	if (find_set(i)!=p){	valid = false;	break;	}

	//trace2(cost, valid);
	if (!valid)	return -1;
	if (left.empty())	return -2;
	return nxt_min;

}

int main(){
	
	ios;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	//t = 1;
	for(int c = 1; c <= t; c++){
		int ans = solve();
		cout << "Case #" << c << " : ";
		if (ans == -1)	cout << "No way" << endl;
		else if (ans == -2)	cout << "No second way" << endl;
		else cout << ans << endl;
	}
	return 0;
}
