#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<ll,ll>  PII;
typedef pair<ll, pair<int, int> > PIII;
typedef long double  ld;
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

ll val[1007][18280];
int n, m;
vector<PII> form[1007][18280];
string temp;

vector<string> split(const string &s,const string &del = " "){
	char *buf, *delim, *word;
	vector<string> res;
	delim = strdup(del.c_str());
	buf = strdup(s.c_str());
	for(word = strtok(buf, delim);	word;	word = strtok(0, delim))
		res.pb(string(word));
	return res;

}

PII parse(string s){

	int r = 0, c = 0;
	reverse(all(s));
	int i = 0, n = s.size();
	while( i < n && isdigit(s[i])){
		r += (s[i]-'0')*pow(10, i);
		i++;
	}
	int cnt = 0;
	while ( i < n ){
		c += (s[i++]-'A'+1)*pow(26, cnt++);
	}
	return mp(r, c);
}

void push_form(int i, int j, string& s){

	s = s.substr(1, s.size()-1);
	string del = "+";
	vector<string> sms = split(s, del);

	// for(auto st : sms)
	// 	trace1(st);
	PII p;

	for (auto st : sms){
		p = parse(st);
		//trace3(st, p.F, p.S);
		form[i][j].pb(p);
	}
}
ll fval(int i, int j){
	if (val[i][j] != 1e10)	return val[i][j];

	val[i][j] = 0;
	for(auto p : form[i][j])
		val[i][j] += fval(p.F, p.S);
	return val[i][j];
}
void solve(){
	
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{

			cin >> temp;
			form[i][j].clear();
			//trace3(i, j, temp);
			if (temp[0] != '='){	val[i][j]=stoi(temp);	}
			else
			{
				push_form(i, j, temp);
				val[i][j] = 1e10;
			}
			//trace2(i, j);
		}
	//cout << "here" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < m; j++)
			if ( val[i][j] != 1e10 )	cout << val[i][j] << " ";
			else cout << fval(i, j) << " ";
		if ( val[i][m] != 1e10 )	cout << val[i][m] << endl;
		else cout << fval(i, m) << endl;

	}

}

int main(){
	
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
