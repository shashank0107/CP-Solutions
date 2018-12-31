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
#define INT_MAX __INT_MAX__
#define INF INT_MAX/10

using namespace std;

vector<double> a, pre;
int n, m;
map<pair<int, double>, double > dp;

void pr(){
	a.clear();
	dp.clear();
	pre.clear();
}

// merge from i till end
double f(int i, double cur){
	
	//cout << i << " " << cur << endl;
	if (i == n)		return cur;
	if (n-i+1 < m)	return -INF;
	if (dp.find(make_pair(i, cur)) != dp.end() ) 	return dp[make_pair(i, cur)];
	
	double ans = -INF;
	for(int j = i+m-2; j < n; j++)
	{
		if (i==0 && j == i+m-2)	continue;
		double sum = cur + pre[j];
		if (i!=0)	sum-=pre[i-1];
		if (i!=0)	sum/=(j-i+2);
		else sum/=(j-i+1);
		//cout << i << " " << j << " " << sum << endl;
		ans = max(ans, f(j+1, sum));
	}
	
	dp[make_pair(i, cur)] = ans;
	//cout << i << " " << cur << " " << ans << endl;
	return ans;
} 

class MergersDivTwo {
public:
	double findMaximum(vector <int> rev, int k) {
		sort(rev.begin(), rev.end());
		pr();
		for(auto i : rev) 	a.push_back(i), pre.push_back(i);
		m = k;	n = a.size();
		for(int i = 1; i < n; i++)	pre[i]+=pre[i-1];
		//for(auto i : pre)	cout << i << " ";cout << endl;
		//cout << "hre" << endl;
		return f(0, 0);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
