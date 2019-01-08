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

const int N = 1e6+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

ll q, n;
bool prime[N];
vector<ll> primes;

void sv(){

	memset(prime, 1, sizeof prime);

	for(ll i = 2; i*i <= (1<<18); i++)
		if (prime[i]){
			//trace(i);
			for(ll j = i*i; j <= (1<<18); j+=i)	prime[j] = false;
			primes.pb(i);
		}
}

void solve(){
	
	sv();
	while(cin >> q)
	{
		if (!q)	break;
		vi ans;

		if (q < 0)	ans.pb(-1), n = -q;
		else n = q;

		if (q == 1){	cout << 1 << " = " << endl;	continue;	}
		else if (q == -1){	cout << -1 << " = -1 x " << endl;	continue;	}

		for(auto i : primes){
			if (i*i > n)	break;
			if (n%i==0)
				while(n%i == 0)
					n/=i, ans.pb(i);
		}
		if (n > 1)	ans.pb(n);

		cout << q << " = ";
		for(int i = 0; i < (int)ans.size()-1; i++)	cout << ans[i] << " x ";
		cout << ans.back() << endl;

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
