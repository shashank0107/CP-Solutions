#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/
#define int ll
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
int cnt[26], n;
string s, t;
set<char> chr;
int fact[37];

int fh(char c, int cn){

	cnt[c-'a']--;
	int ans = 1;
	vi num;
	for(int i = 1; i <= cn; i++) num.pb(i);
	for(auto ch : chr){
		for(int i = 2; i <= cnt[ch-'a']; i++)
		{
			int cur = i;
			for(auto &j : num)
				if (__gcd(j, cur) != 1)
				{
					int g = __gcd(j, cur);
					j/=g;
					cur/=g;
				}
			assert(cur == 1);
		}
	}
	for(auto i : num)	ans *= i;
	cnt[c-'a']++;
	return ans;
}

void solve(){
    
    while(cin >> s){
    	if (s == "#")	break;

    	memset(cnt, 0, sizeof cnt);
    	chr.clear();
    	n = s.size();
    	lp(i,n) cnt[s[i]-'a']++, chr.insert(s[i]);
    	t = s;
    	sort(all(t));

    	int a;
    	int ans = 0;
    	for(int i = 0; i < n; i++)	// fix the current character
    	{
    		for(auto c : chr){
      			if (c == s[i])	break;
    			ans += fh(c, n-i-1);
    		}
       		cnt[s[i]-'a']--;
    		if (cnt[s[i]-'a'] == 0)	chr.erase(s[i]);
       	}
    	cout << setw(10) << ans+1 << endl;
    }	
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    //cin >> t;
    t = 1;
    fact[0] = 1;
    fr(i,1,34)	fact[i] = fact[i-1]*i;
    while(t--)
        solve();

    return 0;
}
