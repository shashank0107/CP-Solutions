/*
  Note that John will plan his travel linearly, i.e., after going to 2 from 1 he won't come back to 1
  Now we'll just find the value of dp[i][ti] : fishes caught in pos i till time ti ( 1 ti = 5 min ),
  this value only depends on the previous state and the time of transition from the previous lake to the current
*/


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

const int N = 200;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/
int n, h, t[N], f[N], d[N], dp[N][N], rem[N][N], limit[N];
int prv[N][N], spent[N];

bool valid(int pos, int time){
    return (time >= 0 && dp[pos][time] != -1);
}

int val(int pos, int ti){
	
	if (ti <= limit[pos]) 
		return ti*f[pos] - (d[pos]*ti*(ti-1))/2;
	else{
		ti = limit[pos];
		return ti*f[pos] - (d[pos]*ti*(ti-1))/2 + f[pos]%d[pos];
	}
}

void tracedp(int pos, int ti){

	spent[pos] = ti - prv[pos][ti];
	if (pos != 0)
		tracedp(pos-1, prv[pos][ti]-t[pos]);
}


void solve(){
    
    while(cin >> n){
        if (n == 0) break;
        memset(dp, -1, sizeof dp);
        memset(spent, 0, sizeof spent);
        cin >> h;   h*=12;
        for(int i = 0; i < n; i++)  cin >> f[i];
        for(int i = 0; i < n; i++)  cin >> d[i];
        for(int i = 1; i < n; i++)	cin >> t[i];       
        for(int i = 0; i < n; i++)	limit[i] = d[i] != 0 ? f[i]/d[i] : INT_MAX;

        for(int ti = 0; ti <= h; ti++)
        	dp[0][ti] = val(0, ti);

        for(int i = 1; i < n; i++)
        	for(int ti = 0; ti <= h; ti++)
        	{
        		// need to calculate dp[i][ti]
        		// we have many choices about the time at which john came to this lake
        		// let that be t_lake
        		dp[i][ti] = -1;

        		for(int t_lake = ti; t_lake >= 0; t_lake--)
        			if (valid(i-1, t_lake-t[i])){

        				if ( dp[i-1][t_lake-t[i]] + val(i, ti-t_lake) > dp[i][ti] )
        					dp[i][ti] = dp[i-1][t_lake-t[i]] + val(i, ti-t_lake),
        					prv[i][ti] = t_lake;
        			}
        		//trace3(i, ti, dp[i][ti]);
        	}

        int ans = -1, lp = -1;
        for(int i = 0; i < n; i++)
        	if (dp[i][h] > ans)	ans = dp[i][h], lp = i;

        tracedp(lp, h);

        for(int i = 0; i < n-1; i++)	cout << spent[i]*5 << ", ";
        cout << spent[n-1]*5 << endl;
    	cout << "Number of fish expected: " << ans << endl;
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
