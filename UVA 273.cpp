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

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )    // a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )    // a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


// reflect p about p0p1
point reflect(point p, point p0, point p1){
    point z = p - p0, w = p1-p0;
    return conj(z/w) * w + p0;
}

// find intersection of segments a-b and c-d if it exists
bool intersectSegment(point a, point b, point c, point d, point& intersect){

    double d1 = cp(a-b, d-c), d2 = cp(a-c, d-c), d3 = cp(a-b, a-c);
    
    if (fabs(d1) < EPS){

        // if ab && cd are parallel and they intersect then return true else false

        double ln = length(a-b);
        if (length(a-d) < ln+EPS && length(b-d) < ln+EPS)
            return true;
        else if (length(a-c) < ln+EPS && length(b-c) < ln+EPS)
            return true;

        ln = length(c-d);
        
        if (length(a-d) < ln+EPS && length(a-c) < ln+EPS)
            return true;
        else if (length(b-c) < ln+EPS && length(b-d) < ln+EPS)
            return true;
        
        return false;    
    }

    double t1 = d2/d1, t2 = d3/d1;
    intersect = a + (b-a)*t1;
    //trace2(t1, t2);
    if (t1 < -EPS || t2 < -EPS || t1 > 1+EPS || t2 > 1 + EPS)   
        return false;           // change to whatever .... here both are segments if ab is a ray : remove t1 > 1+EPS
    return true;
}

// Where is c relative to segment ab
// think of the angle abc
// ccw = +1  => angle > 0 or collinear after b
// ccw = -1  => angle < 0 or collinear before a
// ccw = 0   => undefined : collinear in range [ab]
int ccw(point a, point b, point c){
    point v1 = b-a, v2 = c-a;
    double t = cp(v1, v2);

    if (t > +EPS)   return +1;
    if (t < +EPS)   return -1;
    if ( v1.X*v2.X < -EPS || v1.Y*v2.Y < -EPS )
        return -1;
    if ( norm(v1) < norm(v2)-EPS )  return +1;
    return 0; 
}

int dcmp(double x, double y){
    return fabs(x-y)<EPS ? 0 : (x > y ? 1 : -1);
}

double fixangle(double t){
    return t > 1 ? 1 : (t < -1 ? -1 : t);
}

double getAngle_A_abc(double a, double b, double c){
    double t = b*b + c*c - a*a;
    t/=(2*b*c);
    return acos(fixangle(t));
}

struct stw{
    point a, b;
    stw(point a, point b) : a(a), b(b) {}
};

vector<stw> st;

int n, l, m;
double x, y;
point temp;

int parent[N];
int size[N];

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int u, int v){
    int a = find_set(u);
    int b = find_set(v);
    if (a != b){
        if (size[a] < size[b])  swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void solve(){
    
    cin >> n;
    st.clear();
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        point p1 = point(x, y);
        cin >> x >> y;
        point p2 = point(x, y);
        st.pb(stw(p1, p2));
        make_set(i);
    }

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            // trace2(i, j);
            if (intersectSegment(st[i].a, st[i].b, st[j].a, st[j].b, temp)){
                // cout << "true" << endl;
                // trace2(i, j);    
                union_sets(i, j);
            }
        }

    //for(int i = 0; i < n; i++)  trace2(i, find_set(i));

    while(cin >> l >> m){
        if (l == 0 && m == 0)   break;
        l--, m--;
        if (find_set(l) == find_set(m)) cout << "CONNECTED" << endl;
        else cout << "NOT CONNECTED" << endl;
    }
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
        if (t > 0)  cout << endl;
    }

    return 0;
}
