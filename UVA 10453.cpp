#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
typedef pair<ll, pair<int, int> > PIII;
typedef vector<int>  vi;

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

const int N = 1e3+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

int n, dp[N][N];
string s, s1, s2;

int cost(int i, int j){

    if (i >= j) return 0;

    int &ret = dp[i][j];
    if (ret != -1)  return ret;

    if (s[i] == s[j]){
        return ret = cost(i+1, j-1);
    }

    int choice1 = 1 + cost(i, j-1); // insert to left 
    int choice2 = 1 + cost(i+1, j); // insert to right

    return ret = min(choice1, choice2);
}

void tracedp(int i, int j){

    //trace4(i, j, s1, s2);

    if (i > j)  return;
    if (i == j){ s1 += s[i]; return; }

    if (s[i] == s[j]){
        s1 += s[i];
        s2 += s[j];
        tracedp(i+1, j-1);
        return;
    }
    int optimal = cost(i, j);

    int choice1 = 1 + cost(i, j-1);
    int choice2 = 1 + cost(i+1, j);

    if (optimal == choice1){
        s1+=s[j];
        s2+=s[j];
        tracedp(i, j-1);
    }
    else{
        s2+=s[i];
        s1+=s[i];
        tracedp(i+1, j);
    }
}

void solve(){
    
    while(cin >> s){
        memset(dp, -1, sizeof dp);
        n = s.size();
        cout << cost(0, n-1) << " ";
        s1 = "";
        s2 = "";
        tracedp(0, n-1);
        //trace2(s1, s2);
        reverse(all(s2));
        cout << s1 << s2 << endl;
    }
}

int main(){
    
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
