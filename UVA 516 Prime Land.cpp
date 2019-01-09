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

const int N = 32867;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

vector<ll> primes;
ll x, n, pi, ei;
bool prime[N];
string s;

void sv(){
	memset(prime, 1, sizeof prime);
	for(ll i = 2; i*i <= N; i++)	
		if (prime[i])
			for(ll j = i*i; j <= N; j+=i)	prime[j] = false;

	for(int i = 2; i < N; i++)	if (prime[i])	primes.pb(i);
}

void solve(){
	
	sv();
	//cout << "her" << endl;
	while(getline(cin, s)){

		vector<PII> p1, p2;
		stringstream ss; 
		ss << s;
		if (s[0] == '0')	break;

		while(ss >> pi >> ei )	p1.pb(mp(pi, ei));
		n = 1;
		for(auto i : p1)	n*=pow(i.F, i.S);
		//trace(n);
		n-=1;
		for(auto i : primes){
			if (i*i > n)	break;
			if (n%i == 0){
				int cnt = 0;
				while(n%i == 0)	cnt++, n/=i;
				p2.pb(mp(i, cnt));
			}
		}
		if (n > 1)	p2.pb(mp(n, 1));
		reverse(all(p2));
		for(int i = 0; i < (int)p2.size()-1; i++)	cout << p2[i].F << " " << p2[i].S << " ";
		cout << p2.back().F << " " << p2.back().S << endl;
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
