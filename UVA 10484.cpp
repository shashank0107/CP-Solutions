/*
  Find all the prime factors of !n ( brute force : find prime factors of all no.s from 2 till n ) and keep 
  updating their count in map pn.
  Find all prime factors (and their counts) of d and store in pd.
  For all prime factors of !n, their count must be greater than the corresponding count in d,
  so just take multiply to ans pn[i]-pd[i]+1 for each prime factor of !n 

*/

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

const int N = 1e2+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

ll n, d;

bool comp[N];
vector<ll> primes;

void sv(){
    for(int i = 2; i*i < N; i++)
        if (!comp[i])
            for(int j = i*i; j < N; j+=i)   comp[j] = true;
    for(int i = 2; i < 100; i++)    if (!comp[i])   primes.pb(i);
}

void solve(){
    
    sv();

    while(cin >> n >> d){
        if (n == 0 && d == 0)   break;
        if (n == 0 || n == 1){  if (d == 1) cout << 1 << endl;  else cout << 0 << endl; continue;   }

        map<int, int> pn, pd;
        for(int j = 2; j <= n; j++)
        {
            int num = j;
            for(auto i : primes){
                if (i*i > num)    break;
                if (num%i == 0){
                    int cnt = 0;
                    while(num%i == 0) num/=i, cnt++;
                    pn[i]+=cnt;
                }
            }
            if (num>1)    pn[num]++;
        }
        //for(auto i : pn)    trace2(i.F, i.S);

        for(auto i : primes){
            if (i*i > d)    break;
            if (d%i == 0){
                int cnt = 0;
                while(d%i == 0) d/=i, cnt++;
                pd[i] += cnt;
            }
        }
        if (d > 1)  pd[d]++;
        
        ll ans = 1;
        bool valid = true;
        for(auto i : pn)
        {
            int need = pd.find(i.F) != pd.end() ? pd[i.F] : 0;
            //trace3(i.F, i.S, need);
            if (need > i.S){ valid = false;    }
            ans *= (i.S-need+1);
            pd[i.F] = 0;
        }

        for(auto i : pd)    if (i.S != 0)   valid = false;

        if (!valid) cout << 0 << endl;
        else cout << ans << endl;
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
