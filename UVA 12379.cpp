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

const int N = 1e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int n, m, x;
vi g[N];
vii dep[N];
bool vis[N];
int dp[N], sum[N], ans[N], ret;

void pre(){
    memset(vis, false, sizeof vis);
    lp(i,n+1)   g[i].clear(), dep[i].clear();
    ret = INT_MAX;
    memset(dp, 0, sizeof dp);
    memset(sum, 0, sizeof sum);
    memset(ans, 0, sizeof ans);
}
void dfs(int v){
    vis[v] = true;
    dp[v] = 0;
    sum[v] = 0;
    for(auto nb : g[v]) 
        if (!vis[nb]){
            dfs(nb);
            dep[v].pb(mp(dp[nb], nb));
            sum[v] += 1 + sum[nb];
        }
    sort(all(dep[v]));
    reverse(all(dep[v]));
    if (!dep[v].empty())    dp[v] = 1 + dep[v][0].F;
}
void dfs2(int v){
    vis[v] = true;
    ans[v] = 2*(sum[v]-dp[v]) + dp[v];
    //trace2(v, ans[v]);
    ret = min(ret, ans[v]);

    for(auto nb : g[v]) if (!vis[nb])
    {
        int vsum = sum[v]-sum[nb], pd = dp[nb];
        sum[nb] += vsum;
        bool gr = false;
        if (nb != dep[v][0].S){
            //dp[nb] = max(dp[nb], 1+dp[v]), gr = true;
            if (1+dp[v] >= dp[nb])  
                dp[nb] = 1+dp[v], gr = true;
        }
        else{
            if (dep[v].size() > 1){
                //dp[nb] = max(dp[nb], 1+dep[v][1].F);
                if (2+dep[v][1].F >= dp[nb])
                    dp[nb] = 2+dep[v][1].F, gr = true;
            }
            else{ 
                //dp[nb] = max(dp[nb], 1);
                if (1 >= dp[nb])
                    dp[nb] = 1, gr = true;
            }
        }
        if (gr) dep[nb].insert(dep[nb].begin(), mp(dp[nb]-1, v));
        dfs2(nb);
        sum[nb] -= vsum;
        dp[nb] = pd;
    }
}

void solve(){
    
    cin >> n;
    pre();
    fr(i,1,n){
        cin >> m;
        lp(j,m){
            cin >> x;
            g[i].pb(x);
        }
    }
    dfs(1);
    memset(vis, false, sizeof vis);
    dfs2(1);
    cout << ret << endl;
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
