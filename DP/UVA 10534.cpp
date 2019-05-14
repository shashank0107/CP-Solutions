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

const int N = 5e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int n, a[N];
int lis[N], lds[N], len[N];

void solve(){
    
    while(cin >> n){
        fr(i,1,n) cin >> a[i];
        memset(lis, 0, sizeof lis);
        memset(lds, 0, sizeof lds);
        int ml = 0;

        for(int i = 1; i <= n; i++)
        {
            int idx = lower_bound(len, len+ml, a[i]) - len;
            len[idx] = a[i];
            if (idx == ml)  ml++;
            lis[i] = idx+1;
        }

        ml = 0;
        for(int i = n; i >= 1; i--)
        {
            int idx = lower_bound(len, len+ml, a[i]) - len;
            len[idx] = a[i];
            if (idx == ml)  ml++;
            lds[i] = idx+1;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, 2*min(lis[i],lds[i]) - 1 );
        cout << ans << endl;
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
