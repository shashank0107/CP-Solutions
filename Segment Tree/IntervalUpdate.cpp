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
#define int ll
/*** Template Ends ***/

int a[N], n, tree[4*N], x, r, lazy[4*N];
int m;
string q;

void build(int start, int end, int node){
    if (start == end)
        tree[node] = a[start];
    else{
        build(start, (start+end)/2, 2*node);
        build((start+end)/2+1, end, 2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int start, int end, int node, int idx, int val){
    if (start == end){
        tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if (idx <= mid && idx >= start) update(start, mid, 2*node, idx, val);
    else                            update(mid+1, end, 2*node+1, idx, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void updateRange(int start, int end, int node, int l, int r, int val){

    if (lazy[node] != 0)
    {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l)   return;

    if (start >= l && end <= r)
    {
        tree[node] += (end-start+1)*val;
        if (start != end)
        {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (start+end)/2;
    updateRange(start, mid, 2*node, l, r, val);
    updateRange(mid+1, end, 2*node+1, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int start, int end, int node, int l, int r){
    if (r < start || l > end)   return 0;

    if (lazy[node] != 0)
    {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (l <= start && end <= r) return tree[node];

    int mid = (start+end)/2;
    int p1 = query(start, mid, 2*node, l, r);
    int p2 = query(mid+1, end, 2*node+1, l, r);
    return p1 + p2;
}



void solve(){
    
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    cin >> n >> m;
    lp(i, m){
        cin >> q >> x >> r;
        x--, r--;

        if (x > r){
            if (q == "answer")  cout << 0 << endl;
            else cout << "OK" << endl;
            continue;
        }
        if (q == "answer")  
            cout << query(0, n-1, 1, x, r) << endl;
        else    updateRange(0, n-1, 1, x, r, 1), cout << "OK" << endl;
    }
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fr(i, 1, t){
        cout << "Scenario #" << i << ":" << endl;
        solve();
    }
    return 0;
}
