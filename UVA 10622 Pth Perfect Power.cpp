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
ll n;
vector<ll> primes;
int prime[N];

void sv(){
	memset(prime, 1, sizeof prime);

	for(ll i = 2; i*i <= N; i++)
		if (prime[i]){
			for(ll j = i*i; j <= N; j+=i){
				//if (i == 2)	trace(j);
				prime[j] = false;
			}
		}

	for(ll i = 2; i < N; i++)
		if (prime[i])	{
			primes.pb(i);
			//trace(i);
		}
}

void solve(){
	
	sv();

	while(cin >> n){
		if (n==0)	break;
		if (n==1){	cout << 1 << endl;	continue;	}
		bool isneg = (n < 0);
		if (isneg)	n*=-1;
		vector<ll> pfacs;
		for(auto i : primes){
			if (i*i > n)	break;
			if (n%i == 0){
				ll cnt = 0;
				while(n%i == 0)	n/=i, cnt++;
				pfacs.pb(cnt);
			}
		}
		if (n > 1)	pfacs.pb(1);

		ll ans = pfacs[0];
		for(int i = 1; i < pfacs.size(); i++)	ans = __gcd(ans, pfacs[i]);
		if (isneg){	
			while(ans%2==0)
				ans/=2;
			cout << ans << endl;
		}
		else	cout << ans << endl;
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
