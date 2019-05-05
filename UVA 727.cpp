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
vector<string> v;
string s;

string conv(vector<string> v){

    if (v.empty())  return "";
    if (v.size() == 1)  return v[0];

    //for(auto i : v) cout << i;  cout << endl;
    // find opening bracket
    int s = -1, e = -1;
    lp(i, v.size()) if (v[i] == "("){   s = i;  break;  }
    if (s != -1)    // find close
    {
        int cnt = 1;
        fr(i,s+1,v.size()-1){ 
            if (v[i] == "(") cnt++;
            else if (v[i] == ")") cnt--;
            if (cnt == 0){   e = i;  break;  }   
        }
        //trace2(e, s);
        vector<string> temp, to_send;
        lp(i,s) temp.pb(v[i]);
        fr(i,s+1, e-1) to_send.pb(v[i]);
        temp.pb(conv(to_send));
        fr(i,e+1,v.size()-1) temp.pb(v[i]);

        string ans = conv(temp);
        //trace2("1", ans);
        return ans;
    }

    // find * or /
    int mul=-1, div=-1;
    lp(i,v.size())  
        if (v[i] == "*"){    mul = i;    break;  }
        else if (v[i] == "/"){  div = i;    break;  }

    if (mul != -1)
    {
        vector<string> temp;
        fr(i,0,mul-2)           temp.pb(v[i]);
        temp.pb(v[mul-1]+v[mul+1]+v[mul]);
        fr(i,mul+2, v.size()-1) temp.pb(v[i]);

        string ans = conv(temp);
        //trace2("2", ans);
        return ans;
    }
    if (div != -1)
    {
        vector<string> temp;
        fr(i,0,div-2)           temp.pb(v[i]);
        temp.pb(v[div-1]+v[div+1]+v[div]);
        fr(i,div+2, v.size()-1) temp.pb(v[i]);

        string ans = conv(temp);
        //trace2("3", ans);
        return ans;
    }

    int ad = -1, sb = -1;
    lp(i,v.size())  
        if (v[i] == "+"){    ad = i;    break;  }
        else if (v[i] == "-"){  sb = i;    break;  }

    if (ad != -1)
    {
        mul = ad;
        vector<string> temp;
        fr(i,0,mul-2)           temp.pb(v[i]);
        temp.pb(v[mul-1] + v[mul+1] + v[mul]);
        fr(i,mul+2, v.size()-1) temp.pb(v[i]);

        string ans = conv(temp);
        //trace2("ad", ans);
        return ans;
    }
    if (sb != -1)
    {
        div = sb;
        vector<string> temp;
        fr(i,0,div-2)           temp.pb(v[i]);
        temp.pb(v[div-1]+v[div+1]+v[div]);
        fr(i,div+2, v.size()-1) temp.pb(v[i]);

        string ans = conv(temp);
        //trace2("sb", ans);
        return ans;
    }
    // cerr << "no action found" << endl;
    // for(auto i : v) cerr << i << endl;
    // cerr << endl;
    assert(false);
}

void solve(){
    
    v.clear();
    while(getline(cin, s))
    {
        if (s.size() == 0)  break;
        v.pb(s);
    }
    string ans = conv(v);
    cout << ans << endl;
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    getline(cin, s);
    getline(cin, s);
    while(t--){
        solve();
        if (t > 0)  cout << endl;
    }

    return 0;
}
