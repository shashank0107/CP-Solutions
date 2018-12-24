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
 
const int N = 1e3+7;
const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
 
/*** Template Ends ***/
char a[N][N];
int n, m, sx, sy, ex, ey, xi, yi, x, y;
ll dt[N][N];
int vis[N][N];
 
bool valid(int x, int y){
	return ( x>=0 && x<n && y>=0 && y<m && a[x][y] != 'X');
}
 
ll bfs(){
	if (ex == sx && ey == sy)	return 0;
	queue<PII> q;
	q.push(mp(sx, sy));
	dt[sx][sy] = 0;
	vis[sx][sy] = (1<<8)-1;
 
	while(!q.empty()){
 
		PII p = q.front();	q.pop();
		x = p.F, y = p.S;
		//trace3(x, y, dt[x][y]);
		if ( x == ex && y == ey )	return dt[x][y];
		for(int i = 0; i < 8; i++)	// visiting all the eight directions that can be visited
		{
			int di = 1;
			xi = x+dx[i]*di;
			yi = y+dy[i]*di;
			while( valid(xi, yi) && ((vis[xi][yi]&(1<<i))==0) && dt[xi][yi] >= (dt[x][y]+1) )
			{
				if (vis[xi][yi] == 0)	dt[xi][yi] = 1+dt[x][y],	q.push(mp(xi, yi));
				vis[xi][yi] |= (1<<i);
				di++;
				xi = x+dx[i]*di;
				yi = y+dy[i]*di;
			}
		}
	}
	return -1;
}
 
 
void solve(){
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if ( a[i][j] == 'S')	sx = i, sy = j;
			if ( a[i][j] == 'F')	ex = i, ey = j;
			dt[i][j] = INF;
			vis[i][j] = 0;
		}
	cout << bfs() << endl;
 
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
