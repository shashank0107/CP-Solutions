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

const int N = 12;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
typedef bitset<N> MASK;

int memo[1<<N];
char c;

int best(MASK mask){

    int& ret = memo[mask.to_ulong()];
    if (ret != -1)  return ret;

    ret = 0;

    lp(i,N-2)
    {
        if (mask[i] & mask[i+1] & !mask[i+2])
        {
            mask[i] = mask[i+1] = 0, mask[i+2] = 1;
            ret = max(ret, 1+best(mask));
            mask[i] = 1, mask[i+1] = 1, mask[i+2] = 0;
        }
        else if (!mask[i] & mask[i+1] & mask[i+2])
        {
            mask[i+1] = mask[i+2] = 0, mask[i] = 1;
            ret = max(ret, 1+best(mask));
            mask[i] = 0, mask[i+1] = 1, mask[i+2] = 1;
        }
    }

    return ret;
}

void solve(){
    
    memset(memo, -1, sizeof memo);
    MASK mask;

    lp(i,12){
        cin >> c;
        if (c == '-') mask[i] = 0;
        else mask[i] = 1;
    }
    cout << mask.count() - best(mask) << endl;
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
