#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
typedef pair<ll, pair<int, int> > PIII;
typedef vector<int>  vi;

#define endl         '\n'
#define pb           push_back
#define INF          INT_MAX/10
#define F            first
#define S            second
#define mp           make_pair
#define ios          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define hell         1000000007
#define all(a)       (a).begin(),(a).end()
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

const int N = 2e2+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/
int n, m;
int dp[N][N], x, y;
bool cy[N][N];


void solve(){
    
    int cs = 0;
    while(cin >> m){

        n = 0;
        memset(dp, 0, sizeof dp);
        memset(cy, false, sizeof cy);
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            dp[x][y]++;
            cy[x][y] = true;
            n = max(max(x, y), n);
        }
        assert(n < 200);

        for(int k = 0; k <= n; k++)
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    cy[i][j] |= (cy[i][k] && cy[k][j]);


        for(int k = 0; k <= n; k++)
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++){
                    if (dp[i][j] == -1) continue;
                    if (dp[i][k] != 0 && dp[k][j] != 0){
                        if (dp[i][k] == -1 || dp[k][j] == -1 || cy[k][k] || cy[i][i])
                            dp[i][j] = -1;
                        else dp[i][j] += dp[i][k]*dp[k][j];
                    }
                }

        cout << "matrix for city " << cs++ << endl;
        if (m == 0) continue;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << dp[i][n] << endl;
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
