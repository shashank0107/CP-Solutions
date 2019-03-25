#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*** Template Begins ***/

typedef long long                   ll;
typedef pair<ll,ll>                 PII;
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
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

// Constants //

const int N = 10+7;
const int xinc[] = {0, 0, 1, -1};
const int yinc[] = {1, -1, 0, 0};
const long double PI = acos(-1.0);
const double EPS = 1e-9;

/*** Template Ends ***/

char a[5][N][N], b[5][N][N], r[N][N];
int n; 

void make(int k){
    lp(i,n) lp(j,n) a[k][i][j] = a[0][i][j];
}
void mkb(int k){
    lp(i,n) lp(j,n) b[k][i][j] = b[0][i][j];
}
void rot(){

    lp(i,n/2) fr(j,i,n-2-i)
    {
        char temp = a[0][i][j];
        a[0][i][j] = a[0][n-1-j][i];
        a[0][n-1-j][i] = a[0][n-1-i][n-1-j];
        a[0][n-1-i][n-1-j] = a[0][j][n-i-1];
        a[0][j][n-i-1] = temp;

        temp = b[0][i][j];
        b[0][i][j] = b[0][n-1-j][i];
        b[0][n-1-j][i] = b[0][n-1-i][n-1-j];
        b[0][n-1-i][n-1-j] = b[0][j][n-i-1];
        b[0][j][n-i-1] = temp;

    }
}
void p(int p, int k){
    trace2(p,k);
    if (p == 0)
        lp(i,n){
            lp(j,n) cout << a[k][i][j];
            cout << endl;
        }
    else
        lp(i,n){
            lp(j,n) cout << b[k][i][j];
            cout << endl;
        }
    cout << endl;
}
void ref(){
    lp(i, n) lp(j,n) b[0][i][j] = a[0][n-1-i][j];
}
bool eq1(int p, int k){

    if (p == 0){
        lp(i,n) lp(j,n) if (a[k][i][j] != r[i][j]){ return false; }
        if (k == 0){ cout << "preserved." << endl; return true;   }
        cout << "rotated " << k*90 << " degrees." << endl;
        return true;
    }
    else{
        lp(i,n) lp(j,n) if (b[k][i][j] != r[i][j]){ return false; }
        if (k == 0){ cout << "reflected vertically." << endl; return true;   }
        cout << "reflected vertically and rotated " << k*90 << " degrees." << endl;
        return true;
    }
}

void solve(){
    
    int tc = 1;
    while(cin >> n)
    {
        cout << "Pattern " << tc++ << " was ";
        lp(i,n) lp(j,2*n){
            if (j < n)
                cin >> a[0][i][j];
            else cin >> r[i][j-n];
        }
        bool found = false;
        ref();
        fr(i,1,3){
            rot();
            make(i);
            mkb(i);
        }
        rot();
        fr(i,0,3)
            if (eq1(0,i)){  found = true; break; }
        if (found) continue;
        fr(i,0,3)
            if (eq1(1,i)){  found = true; break; }
        if (found) continue;
        cout << "improperly transformed." << endl;
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
