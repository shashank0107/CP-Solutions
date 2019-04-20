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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
char a[6][N];
ll dp[6][N][6], n;

void solve(){
    
    cin >> n;
    fr(i,1,3) fr(j,1,n) cin >> a[i][j];
    memset(dp, 0, sizeof dp);
    dp[0][0][3] = 1;
    dp[1][0][0] = 1;
    fr(j,1,n) fr(i,1,3)
    {
        if (a[i][j] == '#') continue;
        
        // water from up
        if (a[i-1][j] != '#') dp[i][j][0] = (dp[i-1][j-1][0] + dp[i-1][j-1][2])%hell;

        // water from left
        if (a[i][j-1] != '#') dp[i][j][3] = (dp[i-1][j-1][3] + dp[i+1][j-1][3])%hell;

        // water from below
        if (a[i+1][j] != '#') dp[i][j][2] = (dp[i+1][j-1][0] + dp[i+1][j-1][2])%hell;
    } 
    cout << dp[3][n][0] << endl;
}

signed main(){
    
    ios;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    lp(i,t){
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
