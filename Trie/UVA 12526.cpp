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
struct tnode{
    map<char, tnode*> child;
    int is_word;
    tnode(): is_word(0){}
};
tnode* root;
int sum, n;
string s;

void insert(tnode* now, string& s, int pos){
    if (pos == s.size()){
        now->is_word += 1;
        return;
    }
    if (now->child.find(s[pos]) == now->child.end())
        now->child[s[pos]] = new tnode;
    insert(now->child[s[pos]], s, pos+1);
}
void dfs(tnode* now, int dep){
    if (now == root){
        for(auto ch : now->child)
            dfs(ch.S, dep+1);
        return;
    }
    if (now->is_word > 0)   sum += dep*(now->is_word);

    if (now->child.size() == 1 && now->is_word == 0)
    {
        for(auto ch : now->child)
            dfs(ch.S, dep);
    }
    else
    {
        for(auto ch : now->child)
            dfs(ch.S, dep+1);
    }
}


void solve(){
    
    cout << fixed << setprecision(2);
    while(cin >> n)
    {
        root = new tnode;
        sum = 0;

        lp(i,n){
            cin >> s;
            insert(root, s, 0);
        }

        dfs(root, 0);
        cout << (sum*1.0)/n << endl;
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
