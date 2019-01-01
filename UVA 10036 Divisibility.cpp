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

const int N = 1e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

int n, a[N], k;

bool dp[N][105];

void solve(){
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]%=k;
		if (a[i]<0)	a[i]+=k;
	}
	memset(dp, false, sizeof(dp));

	dp[0][a[0]] = true;

	for(int i = 1; i < n; i++)
		for(int j = 0; j < k; j++)
		{
			if (dp[i-1][j])
			{
				int nxt = (j+a[i])%k;
				int prev = (j-a[i]+k)%k;
				//trace4(i, nxt, prev, j);
				dp[i][nxt] = true;
				dp[i][prev] = true;
			}
		}
	if (dp[n-1][0])	cout << "Divisible" << endl;
	else cout << "Not divisible" << endl;
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
