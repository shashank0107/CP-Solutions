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
const int G = 34943;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
string s;


char hexd(int n){
	if (n < 10)	return n+'0';
	else return 'A'+n-10;
}


void print_hex(int num){

	vector<char> v;
	while(num>0){
		int rem = num%16;
		num/=16;
		v.pb(hexd(rem));
	}
	while(v.size()<4)	v.pb('0');
	reverse(all(v));
	int i = 0;
	if (v.size()%2 == 1){	cout << v[0] << " ";	i++;	}

	int cnt = 0;
	for(; i < v.size(); i++){
		cout << v[i];
		cnt++;
		if (cnt%2 == 0 && cnt != v.size())	cout << " ";
	}
	cout << endl;
}

void solve(){
	
	while(getline(cin, s)){
		if (s == "#")	break;



		ll cur = 0;
		for(auto i : s)
		{
			cur =  (cur<<8);
			int num = i;
			cur += num;
			//trace2(num, cur);
			if (cur > G)
				cur%=G;
		}
		cur<<=16;
		cur%=G;
		cur = (G-cur)%G;


		//trace(cur);
		print_hex(cur);
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
