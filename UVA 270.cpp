#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>                 PII;
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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

int n;
string str;
vector<pair<int, int> > pts;
int x, y;

void solve(){
    
    pts.clear();
    while(getline(cin, str)){
        if (str == "")  break;
        stringstream ss;
        ss << str;
        ss >> x >> y;
        pts.pb(mp(x, y));
    }  

    n = pts.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
    	map<PII, int> m;
    	int same = 0, perp = 0, hori = 0;
        for(int j = 1; j < n; j++)
        {   
        	int num = pts[j].S-pts[i].S;
        	int den = pts[j].F-pts[i].F;
        	if (num == 0 && den == 0)	same++;
        	else if (num == 0)	hori++;
        	else if (den == 0)	perp++;
        	else{
        		int gcd = __gcd(num, den);
        		num /= gcd;
        		den /= gcd;
        		m[mp(num, den)]++;
        		ans = max(ans, m[mp(num, den)]+1);
        	}
        }

        ans = max(ans, 1 + same + hori);
        ans = max(ans, 1 + same + perp);
    }
    cout << ans << endl;

}

int main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    getline(cin, str);
    getline(cin, str);
    while(t--)
        solve();

    return 0;
}
