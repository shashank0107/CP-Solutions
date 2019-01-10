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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

ll n, p, lo, hi, mx, my, px, py;

void red(ll& dist, ll &co, ll cnt){

	if (cnt < 2)
	{
		for(int i = 0; i < lo+1 && dist > 0; i++)
			co--, dist--;
	}
	else
	{
		for(int i = 0; i < lo+1 && dist > 0; i++)
			co++, dist--;
	}
}

void solve(){
	
	while(cin >> n >> p){
		if (!n)	break;

		lo = 1, hi = n;

		while(hi-lo>2){
			ll mid = (hi+lo)/2;
			//trace3(hi, lo, mid);
			if (mid*mid<p)	lo = (mid&1?mid:mid-1);
			else hi = (mid&1?mid:mid+1);
		}
		//trace2(lo, hi);

		ll pt = lo*lo;
		ll dist = p - pt;

		mx = my = (n+1)/2;
		px = py = mx + (lo-1)/2;
		px++;
		py++;
		//trace2(px, py);

		int r = 1, cnt = 0;
		while(dist > 0){
			red(dist, (r?px:py), cnt++);
			//trace2(px, py);
			r = 1-r;
		}
		if (p==1)	px--, py--;
		cout << "Line = " << py << ", column = " << px << "." << endl;
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
