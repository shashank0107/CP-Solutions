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

string s, s1, s2;
int n, dp[N][N], nxt[N][27], prv[N][27];


int best(int i, int j){

    if (i <= -1 || j >= n)  return INT_MAX;
    if (i > j) return 0;
    if (i == j) return 1;
    
    int &ret = dp[i][j];
    if (ret != -1)  return ret;

    if (s[i] == s[j])
        return ret = 2 + best(i+1, j-1);

    int choice1 = best(i, j-1);
    int choice2 = best(i+1, j);

    return ret = max(choice1, choice2);
}

// here we'll find the posn of nearest next and prev alphabet at each index
void preprocess(){

    for(char c = 'a'; c <= 'z'; c++)
        prv[0][c-'a'] = -1;
    prv[0][s[0]-'a'] = 0;

    for(int i = 1; i < n; i++)
        for(char c = 'a'; c <= 'z'; c++){
            if (c == s[i])  prv[i][c-'a'] = i;
            else prv[i][c-'a'] = prv[i-1][c-'a'];
            //trace3(i, c, prv[i][c-'a']);
        }

    for(char c = 'a'; c <= 'z'; c++)
        nxt[n-1][c-'a'] = n;
    nxt[n-1][s[n-1]-'a'] = n-1;

    for(int i = n-2; i >= 0; i--)
        for(char c = 'a'; c <= 'z'; c++){
            if (c == s[i])  nxt[i][c-'a'] = i;
            else nxt[i][c-'a'] = nxt[i+1][c-'a'];
            //trace3(i, j, nxt[i][c-'a']);
        }
}

void tracedp(int i, int j){

    //trace4(i, j, s1, s2);
    if (i > j)  return;
    if (i == j){ s1+=s[i];   return; }

    if (s[i] == s[j]){
        s1 += s[i];
        s2 += s[j];
        tracedp(i+1, j-1);
        return;
    }

    int optimal = best(i, j);

    for(char c = 'a'; c <= 'z'; c++)
    {
        //trace3(c, nxt[i][c-'a'], prv[j][c-'a']);
        if (best(nxt[i][c-'a'], prv[j][c-'a']) == optimal){
            tracedp(nxt[i][c-'a'], prv[j][c-'a']);
            return;
        }
    }
}

void solve(){
    
    while(cin >> s){
        n = s.size();
        memset(dp, -1, sizeof dp);

        best(0, n-1);
        s1 = "", s2 = "";

        preprocess();

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
