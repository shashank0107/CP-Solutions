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
const int W = 1e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

int dp[N][W], w[N], p[N], m, n;


int best(int idx, int avail, int spent){

	//trace2(idx, avail);
	if (idx == 0 || avail == 0)	return 0;

	if (dp[idx][avail] != -1)	return dp[idx][avail];
	int &ret = dp[idx][avail];

	//ret = w[idx] <= avail ? max( best(idx-1, avail-w[idx])+p[idx], best(idx-1, avail) ) : best(idx-1, avail);
	int ret1 = INT_MIN, ret2;
	int n_avail = avail;
	if ( spent <= 2000 && spent+w[idx] > 2000)	n_avail = avail+200;
	if ( w[idx] <= n_avail )	ret1 = best(idx-1, n_avail-w[idx], spent+w[idx]) + p[idx];
	ret2 = best(idx-1, avail, spent);
	ret = max(ret1, ret2);
	//trace3(idx, avail, ret);
	return ret;
}

void solve(){
	
	while(cin >> m >> n){

		for(int i = 1; i <= n; i++)	cin >> w[i] >> p[i]; 
		memset(dp, -1, sizeof dp);
		cout << best(n, m, 0) << endl;
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
