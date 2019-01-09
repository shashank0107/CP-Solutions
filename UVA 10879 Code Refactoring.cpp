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

const int N = 1e7+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
ll n, p1, p2, q;
vector<ll> primes;
bool prime[N];

void sv(){
	memset(prime, 1, sizeof prime);

	for(ll i = 2; i*i <= N; i++)
		if (prime[i]){
			for(int j = i*i; j*j <= N; j+=i)	prime[j] = false;
			primes.pb(i);
		}
}

void solve(){
	
	cin >> n;
	q = n;
	int cnt = 0;

	for(auto i : primes){
		if (i*i > n)	break;
		if (n%i == 0){
			int cp = 0;
			while(n%i == 0){
				n/=i;
				cp++;
				if (cnt == 0)	p1 = pow(i, cp), cnt++;
				else if (cnt == 1){
					p2 = pow(i, cp), cnt++;
					break;
				}
			}
			if (cnt == 2)	break;
		} 
	}
	if (n>1 && cnt < 2)	p2 = n;

}

int main(){
	
	ios;
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	sv();
	cin >> t;
	//t = 1;
	for(int c = 1; c <= t; c++)
	{
		solve();
		cout << "Case #" << c << ": " << q << " = " << p1 << " * " << q/p1 << " = " << p2 << " * " << q/p2 << endl;

	}
	return 0;
}
