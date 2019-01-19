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

const int N = 1e3+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

struct state{
	int a, b;
};

int ma, mb, en;
bool vis[N][N];
PII from[N][N], last;
vector<PII> ans;

void pre(){
	memset(vis, false, sizeof vis);
	for(int i = 0; i <= ma; i++)	
		for(int j = 0; j <= mb;	j++)	from[i][j] = mp(-1, -1);
	ans.clear();
}

void build(){
	PII cur = last;
	PII first = mp(0, 0);
	while(cur != first){
		ans.pb(cur);
		cur = from[cur.F][cur.S];
	}
	ans.pb(first);
	reverse(all(ans));
	//for(auto i : ans)	trace2(i.F, i.S);
}

void print_ans(){

	for(int i = 0; i < ans.size()-1; i++){
		PII cur = ans[i], next = ans[i+1];
		int a = cur.F, b = cur.S, na = next.F, nb = next.S;
		if (na+nb == a+b)
		{
			if (na < a)	cout << "pour A B" << endl;
			else cout << "pour B A" << endl;
		}
		else if (na+nb < a+b)
		{
			if (na < a)	cout << "empty A" << endl;
			else cout << "empty B" << endl;
		}
		else
		{
			if (na > a)	cout << "fill A" << endl;
			else cout << "fill B" << endl;
		}
	}
	cout << "success" << endl;
}

void solve(){
	
	while(cin >> ma >> mb >> en)
	{
		pre();

		queue<PII> q;
		vis[0][0] = true;
		q.push(mp(0, 0));

		while(!q.empty())
		{
			PII p = q.front();	q.pop();
			int a = p.F, b = p.S;

			if (b == en){	last = p;	break;	}

			// 6 choices

			// pour from a to b
			if (a != 0){
				PII next;
				next.S = min(a+b, mb);
				next.F = a-(next.S-b);
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}	

			// pour from b to a
			if (b != 0){
				PII next;
				next.F = min(a+b, ma);
				next.S = b-(next.F-a);
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}	

			// empty a
			if (a != 0){
				PII next;
				next.F = 0;
				next.S = b;
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}

			// empty b
			if (b != 0){
				PII next;
				next.F = a;
				next.S = 0;
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}

			// pour to a
			if (a != ma){
				PII next;
				next.F = ma;
				next.S = b;
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}

			// pour to b
			if (b != mb){
				PII next;
				next.F = a;
				next.S = mb;
				if (!vis[next.F][next.S]){
					q.push(mp(next.F, next.S));
					vis[next.F][next.S] = true;
					from[next.F][next.S] = p;
				}	
			}
		}

		build();
		print_ans();
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
