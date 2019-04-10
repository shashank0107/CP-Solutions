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
int n, m;
string s;

/* Code for splitting a string */

vector<string> split(const string &s,const string &del = " "){
    char *buf, *delim, *word;
    vector<string> res;
    delim = strdup(del.c_str());
    buf = strdup(s.c_str());
    for(word = strtok(buf, delim);    word;    word = strtok(0, delim))
        res.pb(string(word));
    return res;
}

/* Code for splitting string ends */
void solve(){
    
    while(cin >> n >> m){
        map<pair<string, string>, vector<int> > ma[11][11];
        bool found = false;
        getline(cin,s);
        lp(k,n){
            getline(cin, s);
            auto v = split(s, ",");
            //trace2(v.size(), i);
            //for(auto j : v) cout << j << " ";   cout << endl;
            //assert(v.size() == m);
            lp(i,m) fr(j,i+1,m-1)
            {
                ma[i][j][mp(v[i], v[j])].pb(k);
            }
        }
        lp(i,m){ 
            fr(j,i+1,m-1){
                for(auto k : ma[i][j]){
                    if (k.S.size() > 1)
                    {
                        cout << "NO" << endl;
                        cout << k.S[0]+1 << " " << k.S[1]+1 << endl;
                        cout << i+1 << " " << j+1 << endl;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (!found) cout << "YES" << endl;
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
