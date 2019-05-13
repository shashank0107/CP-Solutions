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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/

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

struct tnode{
    map<string, tnode*> child;
};
tnode* root;

int n;
string s;

void insert(tnode* now, vector<string>& path, int pos){
    if (pos == path.size()) return;

    if (now->child.find(path[pos]) == now->child.end())
        now->child[path[pos]] = new tnode;

    insert(now->child[path[pos]], path, pos+1);
}
void printdfs(tnode* now, int dep, string cur){
    if (cur != ""){
        lp(i,dep) cout << " ";  cout << cur << endl;
    }
    for(auto ch : now->child)
        printdfs(ch.S, dep+1, ch.F);
}

void solve(){
    
    while(cin >> n)
    {
        root = new tnode;
        lp(i,n){
            cin >> s;
            vector<string> path = split(s, "\\");
            insert(root, path, 0);
        }
        printdfs(root, -1, "");
        cout << endl;
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
