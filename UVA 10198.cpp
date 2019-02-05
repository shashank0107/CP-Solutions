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

const int N = 1e3+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

/*** BigInteger Class ***/

#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
struct BigInteger {
    static const int BASE = 1000000000; // 10^9
    
    vector<ll> digits;
    
    BigInteger() {
        digits.clear();
        digits.pb(0);
    }
    BigInteger(ll number) {
        digits.clear();
        do {
            digits.pb(number % BASE);
            number /= BASE;
        } while (number);
    }
    
    BigInteger operator + (const BigInteger &b) const {
        BigInteger res = BigInteger();
        res.digits.resize(max(b.digits.size(), digits.size()));
        ll remainder = 0;
        rep(i, res.digits.size()) {
            if (i < digits.size()) remainder += digits[i];
            if (i < b.digits.size()) remainder += b.digits[i];
            res.digits[i] = remainder % BASE;
            remainder /= BASE;
        }
        while (remainder) {
            res.digits.pb(remainder % BASE);
            remainder /= BASE;
        }
        return res;
    }
    
    BigInteger operator * (const BigInteger &b) const {
        BigInteger res = BigInteger();
        res.digits = vector<ll>(b.digits.size() + digits.size() - 1, 0);
        rep(i, digits.size()) rep(j, b.digits.size())
            res.digits[i + j] += digits[i] * (ll)b.digits[j];
        ll remainder = 0;
        rep(i, res.digits.size()) {
            remainder += res.digits[i];
            res.digits[i] = remainder % BASE;
            remainder /= BASE;
        }
        while (remainder) {
            res.digits.pb(remainder % BASE);
            remainder /= BASE;
        }
        return res;
    }
    
    void print() {
        printf("%lld", digits.back());
        repr(i, (int)digits.size() - 1) printf("%09lld", digits[i]);
    }
    
    static BigInteger power(const BigInteger &b, ll k) {
        if (k == 0) return BigInteger(1);
        if (k == 1) return b;
        BigInteger res = power(b, k / 2);
        res = res * res;
        if (k & 1) return res * b;
        return res;
    }
};

///**** ****///


BigInteger dp[N];
int n;

void solve(){
    
    dp[0] = BigInteger(1);
    for(int i = 1; i <= 1000; i++){

        dp[i] = BigInteger(2)*dp[i-1];
        if (i >= 2) dp[i] = dp[i] + dp[i-2];
        if (i >= 3) dp[i] = dp[i] + dp[i-3];
    }

    while(cin >> n){
        dp[n].print();
        puts("");
    }
}

int main(){
    
    //ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    //cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}
