#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
typedef pair<ll, pair<int, int> > PIII;
typedef vector<int>  vi;
typedef vector<pair<int, int> > vii;
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

int a[12][107], n, m, dp[12][107], nxt[12][107];

int path(int i, int j){

    if (j == m) return 0;

    int &ret = dp[i][j];
    if (ret != -1)  return ret;

    vii c(3);
    c[0].F = i-1 >= 0 ? i-1 : n-1,  c[0].S = path(c[0].F, j+1);
    c[1].F = i,                     c[1].S = path(c[1].F, j+1);
    c[2].F = (i+1)%n,               c[2].S = path(c[2].F, j+1);

    sort(all(c));
    int cost = INT_MAX, pos = -1;

    for(auto i : c)
        if (i.S < cost) cost = i.S, pos = i.F;

    nxt[i][j] = pos;
    return ret = a[i][j] + cost;
}

void solve(){
    
    while(cin >> n >> m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)  cin >> a[i][j];
        memset(dp, -1, sizeof dp);

        int cost = INT_MAX, pos = -1;
        for(int i = 0; i < n; i++){
            int cur = path(i, 0);
            if (cur < cost) cost = cur, pos = i;
        }

        for(int i = 0; i < m-1; i++){
            cout << pos+1 << " ";
            pos = nxt[pos][i];
        }
        cout << pos+1 << endl;

        cout << cost << endl;
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
