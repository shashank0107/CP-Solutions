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

const int N = 2e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

int a[N], n, tree[4*N], x, r;
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

int query(int start, int end, int node, int l, int r){
    if (r < start || l > end)   return 0;

    if (l <= start && end <= r) return tree[node];

    int mid = (start+end)/2;
    int p1 = query(start, mid, 2*node, l, r);
    int p2 = query(mid+1, end, 2*node+1, l, r);
    return p1 + p2;
}


void solve(){
    
    int tc = 1;
    while(cin >> n){
        if (n == 0) break;
        if (tc > 1) cout << endl;
        lp(i, n)    cin >> a[i];
        build(0, n-1, 1);
        cout << "Case " << tc++ << ":" << endl;
        while(cin >> q){
            if (q == "END") break;
            else if (q == "S"){
                cin >> x >> r;
                x--;
                update(0, n-1, 1, x, r);
            }
            else{
                cin >> x >> r;
                x--, r--;
                cout << query(0, n-1, 1, x, r) << endl;
            }
        }
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
