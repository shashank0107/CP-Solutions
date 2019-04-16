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
#define fr(i,a,b)    for(int i=a;i<=b;i++)

int goal, n;
double p;
double dp[51][2000][51];

double calc(int i, int cur, int lost_streak){
	if (i == n+1){
		//trace4(i, cur, lost_streak, goal);
		return (cur >= goal) ? 1 : 0;
	}
	if (cur >= goal){	
		//trace4(i, cur, goal, 1)	
		return 1;
	}
	
	double& ret = dp[i][cur][lost_streak];
	if (ret != -1.0)	return ret;
	
	//trace3(i,cur,lost_streak);
	ret = 0;
	long long bet = 1LL<<lost_streak;
	if (cur >= bet){
		ret += p*calc(i+1, (int)(cur+min(bet, (long long)goal)), 0);
		ret += (1-p)*calc(i+1, (int)(cur-bet), lost_streak+1);
	}
	//trace4(i,cur, lost_streak, ret);
	
	return ret;
}

class TestBettingStrategy {
public:
	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		p = (prob*(1.0))/100;
		n = rounds;
		fr(i,0,50) fr(j,0,1999) fr(k,0,50) dp[i][j][k] = -1.0;
		
		goal = goalSum;
		
		return calc(1, initSum, 0);
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
