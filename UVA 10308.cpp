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

const int N = 1e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/
ll n, a, b, w, ans;
string s;
vector<PII> g[N];
bool vis[N];

void pre(){
    for(int i = 0; i < N; i++)  g[i].clear();
    n = 0;
    ans = 0;
    memset(vis, false, sizeof vis);
}

ll ht(int v){

    vis[v] = true;
    ll h1 = 0, h2 = 0;
    //trace(v);
    for(auto p : g[v]){
        ll nb = p.S, ed = p.F;
        if (!vis[nb]){
            ll temp = ht(nb);
            temp += ed;
            //trace2(nb, temp);
            if (temp > h1){   h2 = h1;    h1 = temp;  }
            else if (temp > h2){    h2 = temp;  }
        }
    }
    ans = max(ans, h1+h2);
    //trace3(v, h1, h2);
    return h1;
}

void solve(){
    
    while(cin >> a >> b >> w)
    {
        pre();
        stringstream ss;
        g[a].pb(mp(w, b));
        g[b].pb(mp(w, a));
        getline(cin, s);
        while(getline(cin, s)){
            if (s == "")    break;
            ss.clear();
            ss << s;
            ss >> a >> b >> w;
            //trace3(a, b, w);
            g[a].pb(mp(w, b));
            g[b].pb(mp(w, a));
        }

        ht(1);
        cout << ans << endl;
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
