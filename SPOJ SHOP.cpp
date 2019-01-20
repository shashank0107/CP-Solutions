#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long    ll;
typedef pair<int,int>  PII;
typedef pair<int, pair<int, int> > PIII;
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

const int N = 2e1+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/
char a[N][N];
int h, w;
PII st, de;
int dist[N][N];
bool vis[N][N];


void pre(){
	memset(vis, false, sizeof vis);
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)	dist[i][j] = INT_MAX;
}

bool valid(int i, int j, int di){
	return (i >= 0 && i < h && j >= 0 && j < w && !vis[i][j] && a[i][j] != 'X' && dist[i][j] > di+a[i][j]-'0');
}

int djik(){

	dist[st.F][st.S] = 0;

	priority_queue<PIII, vector<PIII>, greater<PIII> > q;
	q.push(mp(0, st));

	while(!q.empty()){

		PIII p = q.top();	q.pop();
		int ci = p.S.F, cj = p.S.S, di = p.F;

		if (vis[ci][cj])	continue;
		if (ci == de.F && cj == de.S)	break;
		vis[ci][cj] = true;

		for(int i = 0; i < 4; i++){
			int ni = ci+yinc[i];
			int nj = cj+xinc[i];
			if (valid(ni, nj, di)){

				dist[ni][nj] = di + (a[ni][nj] != 'D' ? a[ni][nj]-'0' : 0) ;
				q.push(mp(dist[ni][nj], mp(ni, nj)));
			}
		}
	}

	return dist[de.F][de.S];
}


void solve(){
	
	while(cin >> w >> h){
		if (w == 0 && h == 0)	break;
		pre();
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++){
				cin >> a[i][j];
				if (a[i][j] == 'S')	st.F = i, st.S = j;
				if (a[i][j] == 'D')	de.F = i, de.S = j;
			}

		int ans = djik();
		cout << ans << endl;
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
