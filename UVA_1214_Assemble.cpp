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

map<string, vector<PII> > m;
ll n, b, p, q;
string s1, s2;

bool f(ll q){

	ll sum = 0;
	for(auto it : m)	// select the cheapest item from it.S s.t its quality is greater than q
	{	
		ll cost = INT_MAX;
		for(auto i : it.S)
		{
			if (i.S >= q)	cost = min(cost, i.F);
		}
		sum += cost;
	}
	return sum <= b;
}


void solve(){
	
	m.clear();
	cin >> n >> b;
	for(int i = 0; i < n; i++)
	{
		cin >> s1 >> s2 >> p >> q;
		m[s1].pb(mp(p,q));
	}	

	ll lo = 0, hi = 1e9, mid;
	while(hi-lo>1){
		mid = (lo+hi)/2;
		if (f(mid))	lo = mid;
		else hi = mid;
	}
	if (f(hi))	cout << hi << endl;
	else if (f(lo))	cout << lo << endl;
	else assert(false);

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
