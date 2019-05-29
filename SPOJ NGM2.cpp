#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const int N = 16+7;

int n, a[N], k;
int ans;
bool marked[N];

int lcm(int a, int b) {
    if (a == 0 || b == 0)   return 0;
    return (a*b)/__gcd(a, b);
}

void make(int idx) {

    if (idx == k) {

       int g = 1, cnt = 0;
       for (int i = 0; i < k; i++)
            if (marked[i]){
                g = lcm(g, a[i]), cnt++;
                if (g > 1e10)    g = 1e10;
            }

       if (cnt > 0 && g > 0) {
            ans += cnt&1 ? n/g : -n/g;
            //cout << "ans : " << ans << " cnt : " << cnt << " g : " << g << endl;
       }
       return;
    }

    marked[idx] = true;
    make(idx+1);
    marked[idx] = false;
    make(idx+1);
}

signed main() {

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (a[i] < 0)   a[i] *= -1;
    }

    make(0);
    cout << n-ans << endl;

    return 0;
}
