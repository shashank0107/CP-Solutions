#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<int,int>  PII;
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
#define M_PI         3.14159265358979323846264338327950288
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

const int N = 1e1+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
int n, pos[N][N], dp[N][N];
PII m[N];
stack<char> st;
vector<char> ans;

int best(int l, int r){

	int &ret = dp[l][r];
	if (l == r)	ret = 0;
	if (l == r-1)	ret = m[l].F*m[l].S*m[r].S;

	if (dp[l][r] != -1){
		//trace3(l, r, ret);
		return dp[l][r];
	}
	ret = INF;
	for(int i = l; i < r; i++){
		int cur = best(l, i) + best(i+1, r) + m[l].F*m[r].S*m[i].S;
		//trace2(i, cur);
		if (cur < ret)	ret = cur, pos[l][r] = i;
	}
	//trace3(l, r, ret);
	return ret;
}

void psh(int i){
	st.push('A');
	if (i != 10)	st.push(i+'0');
	else{ st.push('1');	st.push('0');	}
}

void create(int l, int r){

	if (l == r){	psh(l);	return;	}
	st.push('(');
	if (l == r-1){	psh(l);	st.push(' ');	st.push('x'); st.push(' ');	psh(r);	st.push(')');	return;	}

	create(l, pos[l][r]);
	st.push(' ');
	st.push('x');
	st.push(' ');
	create(pos[l][r]+1, r);

	st.push(')');
}

void solve(){
	
	int c = 1;
	while(cin >> n){
		if (!n)	break;
		for(int i = 1; i <= n; i++)	cin >> m[i].F >> m[i].S;
		memset(dp, -1, sizeof dp);
		ans.clear();

		best(1, n); 
		create(1, n);

		while(!st.empty()){	ans.pb(st.top());	st.pop();	}
		reverse(all(ans));

		cout << "Case " << c++ << ": ";
		for(auto i : ans)	cout << i;
		cout << endl;

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
