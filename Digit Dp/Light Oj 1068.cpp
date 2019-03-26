/*
Find the no.s in [a,b] that are divisible by k and the sum of their digits is also divisible by k.
We use the observation that sum can't be greater than 100 so 0 ans for all k > 100
*/

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
int a, b, k;
vector<int> num[2];
int dp[12][100][100][2];

int call(int pos, int cnum, int sum, int f, int i){

    //trace5(pos, cnum, sum, f, i);
    if (k > 85 && cnum > 0) return 0;

    if (pos == num[i].size()){
        if (cnum%k == 0 && sum%k == 0)  return 1;
        return 0;
    }

    int &ret = dp[pos][cnum][sum][f];
    if (ret != -1)  return ret;
    ret = 0;

    int LMT;
    if (f == 0) LMT = num[i][pos];
    else LMT = 9;

    lp(j,LMT+1){
        int ncnum = ((cnum*10)+j)%k;
        int nsum = sum+j;
        int nf = f;
        if (f == 0 && j < LMT) nf = 1;
        int ans = call(pos+1, ncnum, nsum, nf, i);
        ret += ans;
        // trace2(pos, j);
        // trace6(pos+1, ncnum, nsum, nf, i, ans);
    }
    return ret;
}

void solve(){
    
    cin >> a >> b >> k;
    a--;

    if (k > 99){
        cout << 0 << endl;
        return;
    }

    lp(i,2) num[i].clear();
    while(a > 0){
        num[0].pb(a%10);
        a/=10;
    }
    while(b > 0){
        num[1].pb(b%10);
        b/=10;
    }
    lp(i,2) reverse(all(num[i]));

    memset(dp, -1, sizeof dp);
    int ans1 = call(0, 0, 0, 0, 1);
    //trace(ans1);
    memset(dp, -1, sizeof dp);
    int ans2 = call(0, 0, 0, 0, 0);
    //trace2(ans1, ans2);
    cout << ans1-ans2 << endl;
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    lp(i,t){
        cout << "Case " << i+1 << ": ";
        solve();
    }

    return 0;
}
