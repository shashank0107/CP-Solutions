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

const int N = 10+3;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int dp[1<<N][N], n, m, d;
PII pos[N];

int dist(int i, int j){
    return abs(pos[i].F-pos[j].F) + abs(pos[i].S-pos[j].S);
}
int best(bitset<N> mask, int cur){
    int ret = dp[mask.to_ulong()][cur];
    if (ret != -1)  return ret;

    if (mask.count() == 2)  return ret = dist(0, cur);

    bitset<N> nmask = mask;
    nmask[cur] = 0;
    assert(nmask.count() >= 2);
    
    ret = INT_MAX;
    for(int i = 1; i <= d; i++)
        if (nmask[i] == 1)
            ret = min(ret, best(nmask, i) + dist(i, cur));
    
    return ret;
}


void solve(){
    
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    cin >> pos[0].F >> pos[0].S;
    cin >> d;
    fr(i,1,d)   cin >> pos[i].F >> pos[i].S;

    if (d == 0){    cout << 0 << endl;  return; }

    dp[1][0] = 0;
    int ans = INT_MAX;

    bitset<N> mask((1<<(d+1))-1);
    
    for(int bit = 1; bit <= d; bit++)
        ans = min(ans, best(mask, bit) + dist(bit,0));

    cout << "The shortest path has length " << ans << endl;
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
