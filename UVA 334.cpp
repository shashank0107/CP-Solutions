/*
    Just find transitve closure.
    If i is not reachable by j and j is not reachable by i, 
    then they are concurrent 
    Done.
*/

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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

map<string, int> ms;    // string to int
map<int, string> mi;    // int to string
int nc, ne, n, f, l, nm;
string s, s1, s2;
bool dp[200][200];


void pre(){
    ms.clear();
    mi.clear();
    n = 0;
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)    
            dp[i][j] = i == j ? true : false;
}

void solve(){
    
    int cs = 1;
    while(cin >> nc){
        if (nc == 0) break;

        pre();
        
        for(int i = 0; i < nc; i++){
            cin >> ne;
            
            cin >> s;
            ms[s] = n++;
            mi[n-1] = s;
            l = n-1;
            for(int j = 1; j < ne; j++){
                cin >> s;
                ms[s] = n++;
                mi[n-1] = s;
                dp[l][n-1] = true;
                //trace4(l, n-1, mi[l], mi[n-1]);
                l = n-1;
            }
        }

        cin >> nm;
        for(int i = 0; i < nm; i++){
            cin >> s1 >> s2;
            dp[ms[s1]][ms[s2]] = true;
            //trace2(ms[s1], ms[s2]);
        }
        //trace(n);
        // find transitive closure
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dp[i][j] |= (dp[i][k] && dp[k][j]);

        int cnt = 0;
        PII f, s;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if (!dp[i][j] && !dp[j][i]){
                    cnt++;
                    if (cnt == 1)   f = mp(i, j);
                    if (cnt == 2)   s = mp(i, j);
                }

        cout << "Case " << cs++ << ", ";
        if (cnt == 0){  cout << "no concurrent events." << endl;    continue;   }
        else if (cnt == 1){ 
            cout << "1 concurrent events:" << endl;
            cout << "(" << mi[f.F] << "," << mi[f.S] << ") " << endl;
            continue;
        }
        else{
            cout << cnt << " concurrent events:" << endl;
            cout << "(" << mi[f.F] << "," << mi[f.S] << ") ";
            cout << "(" << mi[s.F] << "," << mi[s.S] << ") " << endl;
        }
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
