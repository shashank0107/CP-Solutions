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
ll n, m;
vector<ll> primes;
bool prime[N];

void sv(){
	for(int i = 2; i*i < N; i++)
		if (!prime[i])
			for(int j = i*i; j < N; j+=i)	prime[j] = true;
	for(int i = 2; i < N; i++)	if (!prime[i])	primes.pb(i);
	//for(int i = 0; i < 10; i++)	cout << primes[i] << endl;
}

void solve(){
	
	sv();
	while(cin >> n >> m){
		ll _m = m;
		//if (m == 0){	cout << m << " does not divide " << n << "!" << endl;	continue;	}
		if (m == 0 || m == 1 || n >= m){	cout << m << " divides " << n << "!" << endl;	continue;	}

		vector<PII> pr;

		for(auto i : primes){
			if (i*i > m)	break;
			if (m % i == 0){
				int cnt = 0;
				while(m%i == 0)	m/=i, cnt++;
				pr.pb(mp(i, cnt));
			}
		}
		if (m > 1)	pr.pb(mp(m, 1));
		bool valid = true;
		for(auto i : pr)
		{
			ll need = i.S;
			ll cnt = 0;
			ll p = i.F;

			while(p <= n){
				cnt += n/p;
				if (cnt >= need)	break;
				p = p*i.F;
			}
			//trace3(p, need, cnt);
			if (cnt < need){	valid = false;	break;	}	
		}
		if (valid)	cout << _m << " divides " << n << "!" << endl;
		else cout << _m << " does not divide " << n << "!" << endl;
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
