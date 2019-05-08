#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

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

const int N = 1e2+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int m, n;
vi g[N];
bool vis[N], p[N], done[N];
int a[N][N];
string s, s1, s2;
map<int, string> m2;
map<string, int> m1;
vi ans;
int in[N];

void pre(){
    lp(i,n) g[i].clear();
    memset(vis, false, sizeof vis);
    memset(a, 0, sizeof a);
    m1.clear();
    m2.clear();
    memset(in, 0, sizeof in);
}

vi topo(){
    
    set<int> s;
    lp(i,n) if (in[i] == 0) s.insert(i);
    vi ans;

    while(!s.empty()){
        int v = *s.begin();
        s.erase(v);
        ans.pb(v);

        for(auto nb : g[v]){
            in[nb]--;
            if (in[nb] == 0)    s.insert(nb);
        }
    }
    return ans;
}

void solve(){
    
    int tc = 1;
    while(cin >> n){

        pre();
        lp(i,n){    
            cin >> s;
            m1[s] = i;
            m2[i] = s;
        }
        cin >> m;
        lp(i,m){
            cin >> s1 >> s2;
            int a = m1[s1], b = m1[s2];
            g[a].pb(b);
            in[b]++;
        }

        vi ans = topo();

        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order: ";
        lp(i,(int)ans.size()-1) cout << m2[ans[i]] << " ";
        cout << m2[ans.back()] << "." << endl;
        cout << endl;
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
