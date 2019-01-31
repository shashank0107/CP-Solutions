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

typedef vector<int> vi;
typedef long long ll;
#define pb push_back

#define trace(x)                 cout << #x << ": " << x << endl;
#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;



vector<int> adj(int i){
	vi ans;
	switch(i)
	{
		case 0:
			ans.pb(7);
			break;
		case 1:
			ans.pb(2);	ans.pb(4);
			break;
		case 2:
			ans.pb(1), ans.pb(5), ans.pb(3);
			break;
		case 3:
			ans.pb(2), ans.pb(6);
			break;
		case 4:
			ans.pb(1), ans.pb(5), ans.pb(7);
			break;
		case 5:
			ans.pb(2), ans.pb(4), ans.pb(8), ans.pb(6);
			break;
		case 6:
			ans.pb(3), ans.pb(5), ans.pb(9);
			break;
		case 7:
			ans.pb(4), ans.pb(8), ans.pb(0);
			break;
		case 8:
			ans.pb(5), ans.pb(7), ans.pb(9);
			break;
		case 9: 
			ans.pb(6), ans.pb(8);
			break;
	}
	return ans;
}

class UnsealTheSafe {
public:
	long long countPasswords(int N) {
		
		ll dp[35][11];
		for(int i = 0; i < 10; i++)
			for(int j = 0; j <= N; j++)	dp[j][i] = 0;
		for(int i = 0; i < 10; i++)	dp[1][i] = 1;
		
		for(int i = 1; i < N; i++)
			for(int j = 0; j < 10; j++)
			{	
				//trace2(i, j);
				for(auto nb : adj(j)){
					dp[i+1][nb] += dp[i][j];
					//trace4(i, j, nb, dp[i+1][nb]);
				}
			}
			
		ll ans = 0;
		for(int i = 0; i < 10; i++)
			ans += dp[N][i];
		
		return ans;
	}
};
