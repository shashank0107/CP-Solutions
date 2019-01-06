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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
string s;
stack<string> st[53];


void pre(){
	for(int i = 0; i < 53; i++){	while(!st[i].empty())	st[i].pop();	}

}

int back1(int i){
	for(int j = i-1; j >= 1; j--)
		if (!st[j].empty())	return	j;
	return -1;
}

int back3(int i){
	int cnt = 0;
	for(int j = i-1; j >= 1; j--){
		if (!st[j].empty())	cnt++;
		if (cnt == 3)	return j;
	}
	return -1;
}

int nxt(int i){
	for(int j =i+1; j <= 52; j++)
		if (!st[j].empty())	return j;
	return -1;
}

// can ele at top of i go to top of j
bool can(int i, int j){
	string t1 = st[i].top();
	string t2 = st[j].top();
	return (t1[0] == t2[0] || t1[1] == t2[1]);
}

void tr(int idx){

	if (idx == 53 || idx == -1)	return;
	if (st[idx].empty()){	tr(nxt(idx));	return;	}

	int b3 = back3(idx);
	if (b3 != -1 && can(idx, b3)){
		st[b3].push(st[idx].top());
		st[idx].pop();
		tr(b3);
		return;
	}
	int b1 = back1(idx);
	if (b1 != -1 && can(idx, b1)){
		st[b1].push(st[idx].top());
		st[idx].pop();
		tr(b1);
		return;
	}
	tr(nxt(idx));

}

void solve(){
	
	while(cin >> s){
		if (s == "#")	break;
		pre();
		st[1].push(s);
		for(int i = 2; i <= 52; i++){	cin >> s;	st[i].push(s);	}
			
		tr(1);
		int cnt = 0;
		vi ans;
		for(int i = 1; i <= 52; i++)
			if (!st[i].empty())
				ans.pb(st[i].size());

		if (ans.size() > 1){
			cout << ans.size() << " piles remaining: ";
			for(int i = 0; i < (int)ans.size()-1; i++)	cout << ans[i] << " ";
			cout << ans.back() << endl;
		}
		else{
			cout << ans.size() << " pile remaining: " << ans.back() << endl;
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
