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

ll n, k;
int a[35];
bool prime[N];
vector<ll> primes;


int f(ll k){

	if (a[k] != 0)	return a[k];

	ll n = pow(2, k) - 1;
	//trace(n);
	bool valid = true;
	for(auto i : primes){
		if (i*i > n)	break;
		if (n%i == 0){	valid = false;	break;	}
	}
	if (valid){	a[k] = 1;	return a[k];	}

	if (binary_search(all(primes), k)){	a[k] = 2;	return a[k];	}
	else {	a[k] = 3;	return a[k];	}

}

void sv(){

	memset(prime, 1, sizeof prime);

	for(ll i = 2; i*i <= INT_MAX; i++)
		if (prime[i]){
			for(ll j = i*i; j*j <= INT_MAX; j+=i)	prime[j] = false;
			primes.pb(i);
			//trace(i);
		}
}

void solve(){
	
	sv();
	while(cin >> n){
		if (n == 0)	break;

		if (f(n) == 1)	cout << "Perfect: " << (ll)((pow(2, n-1))*(pow(2, n)-1) ) << "!" << endl;
		else if (f(n) == 3)	cout << "Given number is NOT prime! NO perfect number is available." << endl;
		else if (f(n) == 2)	cout << "Given number is prime. But, NO perfect number is available." << endl;
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
