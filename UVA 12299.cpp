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

int n, a[N], tree[4*N], m;
string q, s;

void build(int st, int en, int node){
    if (st == en){
        tree[node] = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(st, mid, 2*node);
    build(mid+1, en, 2*node+1);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void update(int st, int en, int node, int idx, int val){
    if (st == en){
        tree[node] = val;
        a[st] = val;
        return;
    }
    int mid = (st+en)/2;
    if (idx <= mid)     update(st, mid, 2*node, idx, val);
    else                update(mid+1, en, 2*node+1, idx, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int st, int en, int node, int l, int r){
    if (st > r || en < l)   return INT_MAX;
    if (l <= st && en <= r) return tree[node];
    int mid = (st+en)/2;
    int p1 = query(st, mid, 2*node, l, r);
    int p2 = query(mid+1, en, 2*node+1, l, r);
    return min(p1, p2);
}

/* Code for splitting a string */

vector<int> split(const string &s,const string &del = " "){
    char *buf, *delim, *word;
    vector<string> res;
    delim = strdup(del.c_str());
    buf = strdup(s.c_str());
    for(word = strtok(buf, delim);    word;    word = strtok(0, delim))
        res.pb(string(word));
    vector<int> rr;
    for(auto i : res)
        rr.pb(stoi(i));
    return rr;
}

/* Code for splitting string ends */

void solve(){
    
    cin >> n >> m;
    lp(i, n)    cin >> a[i];
    build(0, n-1, 1);
    lp(i, m)
    {
        cin >> s;
        q = s.substr(0, 5);
        s = s.substr(6, s.size()-7);
        //trace2(q, s);
        vi pos = split(s, ",");
        for(auto &i : pos)   --i;

        if (q == "query")
            cout << query(0, n-1, 1, pos[0], pos[1]) << endl;
        else
        {
            int nn = pos.size();
            int pf = a[pos[0]];
            lp(i, nn-1)
            {
                update(0, n-1, 1, pos[i], a[pos[(i+1)%nn]]);
            }
            update(0, n-1, 1, pos.back(), pf);
        }
        //lp(i, n)    cout << a[i] << " ";    cout << endl;
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
