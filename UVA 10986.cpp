#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
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

const int N = 2e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
vector<PII> g[N];
int n, m, a, b, w, sr, dest;
ll dist[N];
bool vis[N];

void pre(){
	memset(vis, false, sizeof vis);
	for(int i = 0; i <= n; i++)	g[i].clear();
}


ll djikstra(int sr, int dt){

	for(int i = 0; i <= n; i++)	dist[i] = INT_MAX;

	priority_queue<PII, vector<PII>, greater<PII> > q;
	//trace2(sr, dt);
	dist[sr] = 0;
	q.push(mp(0, sr));

	while(!q.empty()){

		PII p = q.top();	q.pop();
		int v = p.S, d = p.F; 
		//trace3(v, d, dt);
		if (vis[v])	continue;
		
		vis[v] = true;
		if (v == dt)	break;

		for(auto i : g[v])
		{
			int nb = i.F, wt = i.S;
			//trace2(nb, wt);
			if (!vis[nb] && dist[nb] > d+wt){
				dist[nb] = d+wt;
				q.push(mp(d+wt, nb));
			}
		}
	}
	return dist[dt];
}


ll solve(){
	
	cin >> n >> m >> sr >> dest;
	pre();
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		g[a].pb(mp(b, w));
		g[b].pb(mp(a, w));
	}
	//trace2(sr, dest);
	ll ans = djikstra(sr, dest);
	//trace(ans);
	return ans;
}

int main(){
	
	ios;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	//t = 1;
	for(int i = 1; i <= t; i++){
		ll ans = solve();
		cout << "Case #" << i << ": ";
		if (ans == INT_MAX)	cout << "unreachable" << endl;
		else cout << ans << endl;
	}
	return 0;
}
