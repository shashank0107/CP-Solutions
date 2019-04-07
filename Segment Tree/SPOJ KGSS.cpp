#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>                 PII;
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
struct leaf{
	int i, j;
	leaf(int i = 0, int j = 0):i(i), j(j) {}
};

leaf tree[4*N];
int a[N], n, q, l, r;

void psh(vii& temp, leaf l){
	if (l.i != -1)	temp.pb(mp(a[l.i], l.i));
	else temp.pb(mp(-1, -1));
	if (l.j != -1)	temp.pb(mp(a[l.j], l.j));
	else temp.pb(mp(-1, -1));
}

void build(int start, int end, int node){
	if (start == end){
		tree[node].i = start;
		tree[node].j = -1;
		return;
	}
	int mid = (start+end)/2;
	build(start, mid, 2*node);
	build(mid+1, end, 2*node+1);
	vii temp;
	psh(temp, tree[2*node]);
	psh(temp, tree[2*node+1]);
	sort(all(temp));
	reverse(all(temp));
	tree[node].i = temp[0].S;
	tree[node].j = temp[1].S;
}

leaf query(int start, int end, int node, int left, int right){
	if (start > right || end < left)	return leaf(-1, -1);
	if (left <= start && end <= right)	return tree[node];
	int mid = (start+end)/2;
	leaf l = query(start, mid, 2*node, left, right);
	leaf r = query(mid+1, end, 2*node+1, left, right);
	vii temp;
	psh(temp, l);
	psh(temp, r);
	sort(all(temp));
	reverse(all(temp));
	return leaf(temp[0].S, temp[1].S);
}

void update(int start, int end, int node, int idx, int val){
	if (start == end){
		a[start] = val;
		return;
	}
	int mid = (start+end)/2;
	if (idx <= mid)	update(start, mid, 2*node, idx, val);
	else 			update(mid+1, end, 2*node+1, idx, val);
	vii temp;
	psh(temp, tree[2*node]);
	psh(temp, tree[2*node+1]);
	sort(all(temp));
	reverse(all(temp));
	tree[node].i = temp[0].S;
	tree[node].j = temp[1].S;
}

char c;
void solve(){
    
    cin >> n;
    lp(i,n) cin >> a[i];
    build(0, n-1, 1);
    cin >> q;
    lp(i,q){
    	cin >> c >> l >> r;
    	if (c == 'Q'){
    		//trace("here");
    		leaf ans = query(0, n-1, 1, l-1, r-1);
    		cout << a[ans.i]+a[ans.j] << endl;
    	}
    	else update(0, n-1, 1, l-1, r);
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
