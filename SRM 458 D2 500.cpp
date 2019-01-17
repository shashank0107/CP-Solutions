#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int a[14], n, t;
long long cnt;
vector<int> v;

void calc();
void f(int idx){
	
	if (idx == n+1){	calc();	return;	}
	
	a[idx] = 1;
	f(idx+1);
	a[idx] = 0;
	f(idx+1);
}

void calc(){
	
	for(int i = 1; i <= n; i++){
	
		if (a[i] == 0)	continue;
		
		for(int j = i+1; j <= n; j++)
			if (a[j] == 0)
				if (v[j-1]-v[i-1] <= 2*t)	cnt++;
	}

}


class BouncingBalls {
public:
	double expectedBounces(vector <int> x, int T) {
		cnt = 0;
		sort(x.begin(), x.end());
		n = x.size();
		v = x, t = T;
		f(1);
		long double ans = cnt;
		cout << ans << endl;
		ans/=(1LL<<n);
		return ans;
	}
};

