#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/
#define int ll
typedef long long                   ll;
typedef pair<int,int>               PII;
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

/*** Template Ends ***/
int n, tree[4*N+7], k, ti, val, pos, a[N];
string s;
char c;

int query(int st, int en, int node, int val){
    if (st == en){
        pos = st;
        return tree[node];
    }
    int mid = (st+en)/2;
    if (tree[2*node]+val <= k)  return query(st, mid, 2*node, val);
    else                        return query(mid+1, en, 2*node+1, val);
}

void update(int st, int en, int node, int idx, int val){
    if (st == en){
        a[st] += val;
        tree[node] += val;
        return;
    }
    if (st > idx || en < idx)   return;
    int mid = (st+en)/2;
    if (idx <= mid) update(st, mid, 2*node, idx, val);
    else            update(mid+1, en, 2*node+1, idx, val);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void solve(){
    
    memset(tree, 0, sizeof tree);
    memset(a, 0, sizeof a);
    cin >> k >> n;
    getline(cin, s);
    for(int cnt = 0; cnt < n; )
    {
        getline(cin, s);
        stringstream ss;
        ss << s;
        if (s[0] == 'b')
        {
            ss >> c >> ti >> val;
            lp(i,ti){
                query(0, N-1, 1, val);
                update(0, N-1, 1, pos, val);
            }
            cnt += ti;
        }
        else
        {
            ss >> val;
            query(0, N-1, 1, val);
            update(0, N-1, 1, pos, val);
            cnt++;
        }
    }
    ll loss = 0;
    int i;
    for(i = 0; i <= N; i++)
        if (a[i] == 0)  break;
        else loss += k-a[i];
    cout << i << " " << loss << endl;
}

signed main(){
    
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
