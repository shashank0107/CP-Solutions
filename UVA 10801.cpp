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

const int N = 1e2+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
int adj[N][N], t[10], fl, n, k, dist[N];
bool vis[N];
string str;
vector<int> ele[10];

void pre(){
	for(int i = 0; i < N; i++)	
		for(int j = 0; j < N; j++)	adj[i][j] = INT_MAX;
	memset(vis, false, sizeof vis);
	for(int i = 0; i <= n; i++)	ele[i].clear();
}


int djik(){

	for(int i = 0; i < N; i++)	dist[i] = INT_MAX;
	dist[0] = 0;
	
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push(mp(0, 0));
	if (k == 0)	return 0;

	while(!q.empty()){

		PII p = q.top(); q.pop();
		int v = p.S, di = p.F;
		//trace4(v, di, vis[v], k);
		if (vis[v])	continue;

		vis[v] = true;
		if (v == k)	break;

		for(int i = 0; i < 100; i++){
			//trace4(i, vis[i], adj[v][i], dist[i]);
			if (!vis[i] && adj[v][i] != INT_MAX && dist[i] > di+adj[v][i]){
				//trace4(dist[i], i, adj[v][i], di);
				dist[i] = di+adj[v][i];
				q.push(mp(dist[i], i));
			}
		}
	}
	return dist[k];
}




void solve(){
	
	while(cin >> n >> k){

		pre();
		for(int i = 0; i < n; i++)	cin >> t[i];
		getline(cin, str);
		for(int i = 0; i < n; i++){
			getline(cin, str);
			stringstream ss;
			ss << str;
			while(ss >> fl){
				ele[i].pb(fl);
			}

		}	

		for(int e = 0; e < n; e++){
			for(auto i : ele[e])
				for(auto j : ele[e])
				{
					int newd = i==0 ? j*t[e] : 60 + abs(i-j) * t[e];
					// trace4(e, i, j, newd);
					if (adj[i][j] > newd)	
						adj[i][j] = newd;
				}
		}

		int ans = djik();
		if (ans == INT_MAX)	cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;


	}


}

int main(){
	
	ios;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	//cin >> t;
	t = 1;
	while(t--)
		solve();

	return 0;
}
