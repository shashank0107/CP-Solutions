#include <iostream>
#include <vector>
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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
string text, word;

vector<int> getLPS(string pat) {
    int n = pat.size();
    vector<int> F(n, 0);

    for (int i = 1, k = 0; i < n; i++) {

        while(k > 0 && pat[i] != pat[k])
            k = F[k-1];

        if (pat[i] == pat[k]) k++;

        F[i] = k;
    }
    return F;
}

vector<int> KMP(string str, string pat) {
    int n = str.size();
    int m = pat.size();
    vector<int> F = getLPS(pat);
    vector<int> occurence;

    for (int i = 0, k = 0; i < n; i++) {

        while(k > 0 && str[i] != pat[k]) 
            k = F[k-1];

        if (str[i] == pat[k])   k++;

        if (k == m) {
            occurence.pb(i-m+1);
            k = F[k-1];
        }
    }
    return occurence;
}

void solve() {
    
    cin >> word >> text;
    cout << KMP(text, word).size() << endl;
}

signed main() {
    
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
