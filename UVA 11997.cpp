/* 
  Consider the answer for 2 arrays (sorted) : a[l] & b[k]
  we store a[0]+b[0], a[1]+b[0], ... a[k-1]+b[0] in priority queue
  then we pop queue k times, each time we pop a[i]+b[j], we push a[i]+b[j+1] into the queue.
  
  So to solve we just keep two arrays and solve using the method above.
*/
#include <bits/stdc++.h>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<int,int>               PII;
typedef pair<ll, pair<int, int> >   PIII;
typedef vector<int>                 vi;
typedef vector<pair<int, int> >     vii;
typedef pair<int, vector<int> >     ivi;
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

const int N = 750+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);

/*** Template Ends ***/
int k, a[N], b[N];

void solve(){
    
    while(cin >> k){
        lp(i,k) cin >> a[i];
        sort(a, a+k);

        for(int c = 1; c < k; c++)
        {
            lp(j,k) cin >> b[j];
            sort(b, b+k);
            priority_queue<PII, vector<PII>, greater<PII> > q;
            lp(i,k) q.push(mp(a[i]+b[0], 0));

            lp(i,k)
            {
                PII p = q.top();    q.pop();
                a[i] = p.F;
                q.push(mp(p.F+b[p.S+1]-b[p.S], p.S+1));
            }
        }
        lp(i,k-1)   cout << a[i] << " ";
        cout << a[k-1] << endl;
    }
}

signed main(){
    
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
