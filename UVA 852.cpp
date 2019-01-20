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

const int N = 9;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};

/*** Template Ends ***/

int a[N+1][N+1];
char c;
bool valid;

bool poss(int i, int j){
	return (i >= 0 && i < N && j >= 0 && j < N);
}

int child(int par){
	if (par == 1)	return 3;
	else return 4;
}

void unmark(int i, int j){

	a[i][j] = 8;
	for(int k = 0; k < 4; k++){
		int ni = i + yinc[k];
		int nj = j + xinc[k];
		if (poss(ni, nj) && a[ni][nj] != 1 && a[ni][nj] != 2 && a[ni][nj] != 8)
			unmark(ni, nj);
	}
}

void fill(int i, int j, int par){

	if (!valid)	return;

	// check validity
	for(int k = 0; k < 4; k++){
		int ni = i+yinc[k];
		int nj = j+xinc[k];
		if (poss(ni, nj) && a[ni][nj] != 0 && a[ni][nj] != par && a[ni][nj] != child(par)){
			valid = false;
			unmark(i, j);
			return;
		}
	}

	a[i][j] = child(par);

	for(int k = 0; k < 4; k++){
		int ni = i+yinc[k];
		int nj = j+xinc[k];
		if (poss(ni, nj) && a[ni][nj] == 0)	fill(ni, nj, par);
	}
}

void pr(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)	cout << a[i][j];
		cout << endl;
	}
}

void solve(){
	
	memset(a, 0, sizeof a);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			cin >> c;
			if (c == 'X')	a[i][j] = 1;
			else if (c == 'O')	a[i][j] = 2;
		}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (a[i][j] == 1 || a[i][j] == 2)
			{
				for(int k = 0; k < 4; k++)
				{
					int ni = i + yinc[k];
					int nj = j + xinc[k];
					if (poss(ni, nj) && a[ni][nj] == 0)
					{
						valid = true;
						fill(ni, nj, a[i][j]);
					}
				}
			}

	//pr();

	int w = 0, b = 0;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			if (a[i][j] == 1 || a[i][j] == child(1))	b++;
			else if (a[i][j] == 2 || a[i][j] == child(2))	w++;

	cout << "Black " << b << " White " << w << endl; 

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
