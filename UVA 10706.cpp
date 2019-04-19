/*
  Just find the sequence no. in which n belongs then just iterate all the no.s of that sequence one by one to find the digit 
  at the required position.
*/
#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

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
#define int ll
/*** Template Ends ***/
int dp[N], cnt[N], last[N], n;

int dig(int n){
    int cnt = 0;
    while(n > 0) cnt++, n/=10;
    return cnt;
}


void pre(){
    dp[1] = 1, cnt[1] = 1, last[1] = 1;
    for(int i = 2; i <= 1e5; i++)
    {
        last[i] = last[i-1]+1;
        cnt[i]  = cnt[i-1]+dig(last[i]);
        dp[i]   = dp[i-1]+cnt[i];  
    }
    //trace2(last[(int)1e5], dp[(int)1e5]);
}

void solve(){
    
    cin >> n;
    int sn = -1;
    for(int i = 1; i < 1e5; i++)
    {
        if (dp[i] >= n)
        {
            sn = i;
            break;
        }
    }
    assert(sn != -1);
    //trace3(sn, last[sn], dp[sn]);

    n -= dp[sn-1];
    // we have no.s from 1 till last[i] and we have to calculate the digit at position n
    int done = 0;
    for(int num = 1; num <= last[sn]; num++)
    {
        int cur = dig(num);
        if (cur < n) n -= cur;
        else
        {
            vi dig;
            int temp = num;
            while(temp > 0) dig.pb(temp%10), temp/=10;
            reverse(all(dig));
            cout << dig[n-1] << endl;
            return;
        }
    }
}

signed main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    pre();
    int t;
    cin >> t;
    //t = 1;
    while(t--)
        solve();

    return 0;
}
