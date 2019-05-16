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

const int N = 2e4+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int n, a[N], d[N], s[N];


void solve(int tt){
    memset(s, -1, sizeof s);
    cin >> n;
    fr(i,1,n-1) cin >> a[i];

    int as = -1, ae = -1, ans = INT_MIN;
    fr(i,1,n-1)
    {
        if (d[i-1] >= 0 && i-1 > 0)
        {
            d[i] = d[i-1] + a[i];
            s[i] = s[i-1];
        }
        else
        {
            d[i] = a[i];
            s[i] = i;
        }
        if (d[i] > ans){
            ans = d[i];
            as = s[i];
            ae = i;
        }
        else if (d[i] == ans && i-s[i] > ae-as){
            ans = d[i];
            as = s[i];
            ae = i;
        }
        //trace2(i, d[i]);
    }
    if (ans > 0)    cout << "The nicest part of route " << tt << " is between stops " << as << " and " << ae+1 << endl;
    else cout << "Route " << tt << " has no nice parts" << endl;
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    lp(i,t){
        solve(i+1);
    }

    return 0;
}
