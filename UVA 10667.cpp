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
int n, b, a[N][N], r1, c1, r2, c2, dp[N][N];

int rectInHistogram(vector<int>& a){
    a.pb(-1);
    int n = a.size();
    int ans = 0;

    stack<PII> st;
    for(int i = 0; i < n; i++)
    {
        PII p = mp(a[i], i);
        while(!st.empty() && st.top().F > a[i])
        {
            ans = max(ans, st.top().F*(i-st.top().S));
            p.S = st.top().S;
            st.pop();
        }
        st.push(p);
    }
    return ans;
}

void solve(){
    
    memset(a, 0, sizeof a);
    memset(dp, 0, sizeof dp);
    cin >> n;
    cin >> b;
    fr(i,1,n) fr(j,1,n) a[i][j] = 1;
    lp(i,b){
        cin >> r1 >> c1 >> r2 >> c2;
        fr(i,r1,r2) fr(j,c1,c2) a[i][j] = 0;
    }

    fr(i,1,n) fr(j,1,n)
    {
        if (a[i][j] == 1)   dp[i][j] = a[i][j] + dp[i-1][j];
        else dp[i][j] = 0;
    }

    int ans = 0;
    fr(i,1,n)
    {
        vector<int> v(dp[i]+1, dp[i]+n+1);
        int cur = rectInHistogram(v);
        ans = max(ans, cur);
        //trace2(i, cur);
    }
    cout << ans << endl;
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
