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

int n, p, l;

int msk[17];
int dp[1<<17];
bool cover[1<<17];

int calc(int mask){
    if (mask == 0)  return 0;

    int &ret = dp[mask];
    if (ret != -1)  return ret;

    ret = 0;
    for(int i = mask; i > 0; i=(i-1)&mask)  if (cover[i]) ret = max(ret, 1+calc(mask&(~i)));
    return ret;
}

void solve(){
    
    int tc = 1;
    while(cin >> n){
        if (n == 0) break;
        memset(msk, 0, sizeof msk);
        memset(cover, false, sizeof cover);
        memset(dp, -1, sizeof dp);

        lp(i,n){
            cin >> l;
            msk[i] |= (1<<i);
            lp(j,l){
                cin >> p;
                msk[i] |= (1<<p);
            }
            //lp(i,17) if ((1<<i)&ms[])
        }
        lp(mask,(1<<n))
        {
            int cv = 0;
            lp(i, 17)
                if (mask&(1<<i))
                {
                    lp(j,17)
                        if (msk[i]&(1<<j)) cv |= (1<<j);
                } 
            if (cv == (1<<n)-1) cover[mask] = 1;
        }

        cout << "Case " << tc++ << ": " << calc((1<<n)-1) << endl;
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
