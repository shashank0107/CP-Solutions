#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<ll,ll>                 PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;
typedef vector<pair<int, int> >     vii;

#define endl         '\n'
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
#define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
#define all(a)       (a).begin(),(a).end()
#define fr(i,a,b)    for(int i=a;i<=b;i++)
#define lp(i,a)      for(int i=0;i< a;i++)
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

int tree[4*N], lazy[4*N], n, m, q, l, r;

void updateRange(int start, int end, int node, int l, int r){

    if (lazy[node])
    {
        tree[node] = (end-start+1) - tree[node];
        if (start != end)
        {
            lazy[2*node] = 1 - lazy[2*node];
            lazy[2*node+1] = 1 - lazy[2*node+1];
        }
        lazy[node] = 0;
    }
    if (r < start || l > end)   return;
    if (l <= start && end <= r)
    {
        tree[node] = (end-start+1) - tree[node];
        if (start != end)
        {
            lazy[2*node] = 1 - lazy[2*node];
            lazy[2*node+1] = 1 - lazy[2*node+1];
        }
        return;
    }
    int mid = (start+end)/2;
    updateRange(start, mid, 2*node, l, r);
    updateRange(mid+1, end, 2*node+1, l, r);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int start, int end, int node, int l, int r){
    if (lazy[node])
    {
        tree[node] = (end-start+1) - tree[node];
        if (start != end)
        {
            lazy[2*node] = 1 - lazy[2*node];
            lazy[2*node+1] = 1 - lazy[2*node+1]; 
        }
        lazy[node] = 0;
    }
    if (r < start || l > end)   return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start+end)/2;
    int p1 = query(start, mid, 2*node, l, r);
    int p2 = query(mid+1, end, 2*node+1, l, r);
    return p1+p2;
}


void solve(){
    
    cin >> n >> m;

    lp(i, m)
    {
        cin >> q >> l >> r;
        l--, r--;
        if (q == 0){
            updateRange(0, n-1, 1, l, r);
        }
        else
        {
            cout << query(0, n-1, 1, l, r) << endl;
        }
    }
}

signed main(){
    
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
