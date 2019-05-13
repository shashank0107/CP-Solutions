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

const int N = 5e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int tree[N][10], n;
int root, cur;
bool is_word[N], is_pre[N];
string s;

bool insert(int now, string& s, int pos){
    if (is_word[now])   return false;
    if (pos == s.size()){
        if (is_pre[now])    return false;
        is_word[now] = true;
        return true;
    }
    is_pre[now] = true;
    int c = s[pos]-'0';
    if (tree[now][c] == -1) tree[now][c] = ++cur;
    return insert(tree[now][c], s, pos+1);
}

void solve(){
    
    memset(tree, -1, sizeof tree);
    memset(is_word, false, sizeof is_word);
    memset(is_pre, false, sizeof is_pre);
    root = 1;
    cur = 1;

    bool valid = true;
    cin >> n;
    lp(i,n){
        cin >> s;
        if (valid)  
            valid &= insert(root, s, 0);
        //trace2(s, valid);
    }
    if (valid) cout << "YES" << endl;
    else cout << "NO" << endl;
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
