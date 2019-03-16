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

int n, a[N], k;
int tree[4*N];
char c;
int l, r, id, va;

void build(int start, int end, int index){
    if (start == end){
        tree[index] = a[start];
        return;
    }
    build(start, (start+end)/2, 2*index);
    build((start+end)/2+1, end, 2*index+1);
    tree[index] = tree[2*index] * tree[2*index+1];
}

void update(int start, int end, int index, int i,int val){

    if (start == end){
        tree[index] = val;
        return;
    }
    int mid = (start+end)/2;
    if (i <= mid && i >= start) update(start, mid, 2*index, i, val);
    else                        update(mid+1, end, 2*index+1, i, val);
    tree[index] = tree[2*index] * tree[2*index+1];
}

int query(int start, int end, int index, int left, int right){

    if (right < start || end < left)    return 1;

    if (start >= left && end <= right)  return tree[index];
    
    int mid = (start+end)/2;
    int p1 = query(start, mid, 2*index, left, right);
    int p2 = query(mid+1, end, 2*index+1, left, right);
    //trace3(start, end, p1*p2);
    return p1*p2;
}


void solve(){
    
    while(cin >> n >> k){
        memset(tree, 0, sizeof tree);
        memset(a, 0, sizeof a);
        lp(i, n)    cin >> a[i];
        lp(i, n)    
            if (a[i] < 0)   a[i] = -1;
            else if (a[i] > 0)  a[i] = 1;
            else a[i] = 0;

        build(0, n-1, 1);
        //lp(i, 2*n+1)    trace2(i, tree[i]);
        lp(t, k)
        {
            cin >> c;
            if (c == 'C'){
                cin >> id >> va;
                if (va > 0) va = 1;
                else if (va < 0)    va = -1;
                else va = 0;
                id--;
                update(0, n-1, 1, id, va);
            }
            else{
                cin >> l >> r;
                l--, r--;
                int ans = query(0, n-1, 1, l, r);
                //trace(ans);
                if (ans == 0)       cout << 0;
                else if (ans > 0)   cout << '+';
                else                cout << '-';
            }
            //lp(i, 2*n+1)  trace2(i, tree[i]);
        }
        cout << endl;
    }
}

int main(){
    
    ios;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    //cin >> t;
    t = 1;
    while(t--)
        solve();

    return 0;
}
