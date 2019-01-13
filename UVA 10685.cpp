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

const int N = 5e3+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
int n, m, ans;
map<string, int> ma;
string s, b;

int parent[N], size[N];

void pre(){
	memset(parent, 0, sizeof parent);	
	ma.clear();
}

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
		if (size[a] > size[b])	swap(a, b);
		parent[a] = b;
		size[b] += size[a]; 
	}
}

void solve(){
	
	while(cin >> n >> m){
		if (n == 0 && m == 0)	break;
		pre();
	
		for(int i = 1; i <= n; i++){
			cin >> s;
			ma[s] = i;
			make_set(i);
		}

		for(int i = 0; i < m; i++){
			cin >> s >> b;
			//trace4(ma[s], ma[b], size[ma[s]], size[ma[b]]);
			union_set(ma[s], ma[b]);
			//trace2(size[ma[s]], size[ma[b]]);
		}
		ans = 0;
		for(int i = 1; i <= n; i++){
			//trace3(i, size[i], parent[i]);
			ans = max(ans, size[i]);
		}
		cout << ans << endl;
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
