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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/
vector<PII> g[N];
int n, m, s, e, a, b, w;
int dist[N];

void pre(){
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 0; i <= n; i++) dist[i] = INT_MAX;
}


void solve(){
    
    cin >> n >> m >> s >> e;
    pre();
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        g[a].pb(mp(w, b));
        g[b].pb(mp(w, a));
    }

    priority_queue<PII, vector<PII>, greater<PII> > q;
    dist[s] = 0;
    q.push(mp(0, s));

    while(!q.empty()){

        PII p = q.top();    q.pop();
        int v = p.S, d = p.F;
        //trace2(v, d);
        if (v == e){
            cout << dist[v] << endl;
            return;
        }

        for(auto i : g[v]){
            int nb = i.S, ed = i.F;
            if (dist[nb] > d + ed){
                dist[nb] = d + ed;
                q.push(mp(dist[nb], nb)); 
            }
        }
    }
    cout << "NONE" << endl;
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
