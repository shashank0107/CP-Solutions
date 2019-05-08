#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>               PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;
typedef vector<pair<int, int> >     vii;
typedef vector<pair<PII, int> >     viii;
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
int n, m, a, b, w, q;
int d1[N][N], d2[N][N];

void pre(){
    lp(i,n) lp(j,n) d1[i][j] = INF, d2[i][j] = INF;
    lp(i,n) d1[i][i] = 0;
}

void solve(){
    
    int tc = 1;
    while(cin >> n >> m){
        
        pre();
        viii ed;
        lp(i,m){
            cin >> a >> b >> w;
            d1[a][b] = w;
            d1[b][a] = w;
            ed.pb(mp(mp(a, b), w));
            ed.pb(mp(mp(b, a), w));
        }

        lp(k,n) lp(i,n) lp(j,n) 
            d1[i][j] = min(d1[i][j], d1[i][k]+d1[k][j]);

        lp(i,n) lp(j,n)
        {
            int mn = INF;
            //trace3(i, j, d1[i][j]);
            for(auto e : ed)
            {
                int dn = d1[i][e.F.F] + e.S + d1[e.F.S][j];
                // trace4(dn, e.S, e.F.F, e.F.S);
                // trace2(d1[i][e.F.F], d1[e.F.S][j]);
                if (dn > d1[i][j])  mn = min(mn, dn);
            }
            d2[i][j] = mn;
            //trace3(i, j, d2[i][j]);
        }

        cin >> q;
        cout << "Set #" << tc++ << endl;
        lp(i,q){
            cin >> a >> b;
            if (d2[a][b] != INF)    cout << d2[a][b] << endl;
            else            cout << "?" << endl;
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
