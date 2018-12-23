#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
typedef pair<int, pair<int, int> > PIII;
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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

int n, m, dp[1<<12][12], ox, oy;
char a[25][25];
bool vis[25][25];
vector<PII> dirty;

int bfs(int x, int y, int dx, int dy){

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)	vis[i][j] = false;
	queue<PIII> q;
	q.push(mp(0, mp(x, y)));
	vis[x][y] = true;
	if (dx == x && dy == y)	return 0;

	while(!q.empty())
	{
		PIII p = q.front();	q.pop();
		x = p.S.F, y = p.S.S;

		for(int i = 0; i < 4; i++)
		{
			int xi = x + xinc[i];
			int yi = y + yinc[i];
			if (xi>=0 && xi < n && yi>=0 && yi < m && !vis[xi][yi] && a[xi][yi]!='x')
			{
				q.push(mp(p.F+1, mp(xi, yi)));
				vis[xi][yi] = true;
				if (xi == dx && yi == dy)
					return p.F+1;
			}
		}
	}
	return INF;
}

int dis(){

	int n = dirty.size();
	if ( n == 0 )	return 0;
	for(int mask = 1; mask < (1<<n); mask++)
	{
		if ( log2(mask) == ceil(log2(mask)) )	// mask = 2^i
		{
			int i = log2(mask);
			dp[mask][i] = bfs(ox, oy, dirty[i].F, dirty[i].S);
			if (dp[mask][i] == INF)	return -1;
		}

		for(int i = 0; i < n; i++)
		{
			if ( ( mask & (1<<i) ) == 0)			// if ith bit is unset in mask
			{
				dp[mask+(1<<i)][i] = INT_MAX;
				for(int j = 0; j < n; j++)
				{
					if ( ( mask & (1<<j)) != 0 )
					{
						dp[mask+(1<<i)][i] = min(dp[mask+(1<<i)][i], dp[mask][j] + bfs(dirty[j].F, dirty[j].S, dirty[i].F, dirty[i].S));
					}
				}
			}
		}
	} 
	int ans = INT_MAX;
	for(int i = 0; i < n; i++)
		ans = min(ans, dp[(1<<n)-1][i]);

	return ans;
}

void solve(){
	
	while(cin >> m >> n){
		dirty.clear();
		if ( n == 0 && m == 0)	break;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '*')	dirty.pb(mp(i, j));
				if (a[i][j] == 'o')	ox = i, oy = j;
			}

		cout << dis() << endl;
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
