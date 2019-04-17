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
map<int, string> m;
int n, r;
string st;
double p[16][16];
double dp[16][5];

void solve(){
    
    cout << fixed << setprecision(2);
    n = 16, r = 4;
    lp(i,n){
        cin >> st;
        m[i] = st;
    }
    lp(i,n) lp(j,n){ cin >> p[i][j]; p[i][j]/=100;   }

    lp(i,n) dp[i][0] = 1;

    fr(round, 1, 4) fr(i, 0, 15)
    {
        int cnt = 1<<round;
        int l = cnt*(i/cnt), r = l+cnt-1;
        
        int mid = (l+r)/2;
        if (i <= mid)
        {
            for(int nb = mid+1; nb <= r; nb++)
                dp[i][round] += p[i][nb]*dp[nb][round-1];
            dp[i][round] *= dp[i][round-1];
        }
        else
        {   
            for(int nb = l; nb <= mid; nb++)
                dp[i][round] += p[i][nb]*dp[nb][round-1];
            dp[i][round] *= dp[i][round-1];
        }
        // trace5(i, l, r, round, dp[i][round]);
        // trace(mid);
    } 
    lp(i,n){
        cout.width(10);
        cout << left << m[i] << " p=" << dp[i][4]*100 << "%" << endl;
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
