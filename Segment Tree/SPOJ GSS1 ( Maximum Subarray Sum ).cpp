#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int ll
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
 
// Debug //
 
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
 
// Constants //
 
const int N = 5e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;
 
/*** Template Ends ***/
struct leaf{
    int pref, suf, ans, sum;
    leaf(int pref=0, int suf=0, int ans=0, int sum=0): pref(pref), suf(suf), ans(ans), sum(sum) {}
    bool operator==(const leaf& oth){
        return oth.pref == pref && oth.suf == suf && oth.ans == ans && oth.sum == sum;
    }
};
 
int a[N], n, m, l, r;
leaf tree[4*N], inv;
 
leaf combine(leaf& left, leaf& right){
    leaf res;
    if (left == inv)    return right;
    if (right == inv)   return left;
    res.pref = max(left.pref, left.sum+right.pref);
    res.suf = max(right.suf, right.sum+left.suf);
    res.ans = max(max(left.ans, right.ans), left.suf+right.pref);
    res.sum = left.sum + right.sum;
 
    return res;
}
 
void build(int start, int end, int node){
    if (start == end){
        tree[node] = leaf(a[start], a[start], a[start], a[start]);
        return;
    }
    int mid = (start+end)/2;
    build(start, mid, 2*node);
    build(mid+1, end, 2*node+1);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

void update(int start, int end, int node, int idx, int val){
    if (start == end){
        a[start] = val;
        tree[node] = leaf(a[start], a[start], a[start], a[start]);
        return;
    }
    int mid = (start+end)/2;
    if (idx <= mid) update(start, mid, 2*node, idx, val);
    else            update(mid+1, end, 2*node+1, idx, val);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
} 

leaf query(int start, int end, int node, int l, int r){
    if (start > r || end < l)   return inv;
    if (l <= start && end <= r) return tree[node];
    int mid = (start+end)/2;
    leaf lf = query(start, mid, 2*node, l, r);
    leaf rh = query(mid+1, end, 2*node+1, l, r);
    return combine(lf, rh);
}
 
void solve(){
    
    cin >> n;
    inv = leaf(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
    lp(i,n) cin >> a[i];
    build(0, n-1, 1);
 
    cin >> m;
    int t;
    lp(i,m){
        cin >> t >> l >> r;
        if (t == 1){
            leaf res = query(0, n-1, 1, l-1, r-1);
            cout << res.ans << endl;
        }
        else{
            update(0, n-1, 1, l-1, r);
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
