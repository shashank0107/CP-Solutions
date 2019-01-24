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

const int N = 1e5+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

/* Geometry Template Begins */
typedef complex<double> point;

#define X real()
#define Y imag()
#define cp(a, b)        ( (conj(a)*(b)).imag() )    // a*b sin(T)   --> 0 if parallel
#define dp(a, b)        ( (conj(a)*(b)).real() )    // a*b cos(T)   --> 0 if perpendicular
#define vec(a, b)       ( (b)-(a) )


// reflect p about p0p1
point reflect(point p, point p0, point p1){
    point z = p - p0, w = p1-p0;
    return conj(z/w) * w + p0;
}

// find intersection of segments a-b and c-d if it exists
bool intersectSegment(point a, point b, point c, point d, point& intersect){

    double d1 = cp(a-b, d-c), d2 = cp(a-c, d-c), d3 = cp(a-b, a-c);
    if (fabs(d1) < EPS)
        return false;   // parallel

    double t1 = d2/d1, t2 = d3/d1;
    intersect = a + (b-a)*t1;

    if (t1 < -EPS || t2 < -EPS || t1 > 1+EPS || t2 > 1 + EPS)   
        return false;           // change to whatever .... here both are segments if ab is a ray : remove t1 > 1+EPS
    return true;
}

/* Geometry Template Ends */

void solve(){
    
    int n, x1, x2, y1, y2;
    cin >> n;

    vector<pair<point, point> > segs(n);
    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        point p1(x1, y1), p2(x2, y2);
        segs[i].F = p1, segs[i].S = p2;
    }

    int cnt = 0;
    point temp;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if (intersectSegment(segs[i].F, segs[i].S, segs[j].F, segs[j].S, temp)){
                //trace2(i, j);
                cnt++;
            }

    cout << n+2*cnt << endl;
}

int main(){
    
    ios;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
        solve();
        if (t>0)    cout << endl;
    }

    return 0;
}
