#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>               PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;

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
int n, k;
string temp;

int tree[N][26];
int root = 1;
bool is_word[N];
int cnt[N];
int cur = 1;

void insert(string s){
    int now = root;
    cnt[now]++;
    int n = s.size();

    for(int i = 0; i < n; i++){
        int c = s[i]-'a';
        if (tree[now][c] == -1){
            cur++;
            tree[now][c] = cur;
        }
        now = tree[now][c];
        cnt[now]++;
    }
    is_word[now] = true;
}

void Ins(vector<string>& ans, stack<char> str){
    string temp;
    while(!str.empty()){    temp += str.top();  str.pop();  }
    reverse(all(temp));
    ans.pb(temp);
}

vector<string> findWords(string pre){
    int now = root;
    int n = pre.size();

    for(int i = 0; i < n; i++){
        int c = pre[i]-'a';
        if (tree[now][c] == -1) return vector<string>();
        now = tree[now][c];
    }

    stack<char> str;
    for(auto i : pre) str.push(i);

    vector<string> ans;
    stack<pair<int, pair<int,int> > > choices;

    choices.push(mp(0, mp(now,-1)) );
    
    while(!choices.empty()){
        auto p = choices.top(); choices.pop();

        // trace3(p.F, p.S.F, p.S.S);
        if (p.F == 1){  
            if (p.S.S != -1)    str.pop();  
            continue;  
        }

        choices.push(mp(1, p.S));
        if (p.S.S != -1)  str.push('a'+p.S.S);
        if (p.S.S != -1 && is_word[p.S.F])  Ins(ans, str);  

        for(int c = 0; c < 26; c++)
            if (tree[p.S.F][c] != -1){ 
                choices.push(mp(0, mp(tree[p.S.F][c], c)) );
            }

    }
    return ans;
}

void solve(){
    
    memset(tree, -1, sizeof tree);

    cin >> n;
    lp(i,n){
        cin >> temp;
        insert(temp);
    }
    cin >> k;
    lp(i,k){
        cin >> temp;
        vector<string> ans = findWords(temp);
        cout << "Case #" << i+1 << ":" << endl;
        if (ans.empty())    cout << "No match." << endl;
        else{
            sort(all(ans));
            for(auto i : ans)   cout << i << endl;
        }
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
