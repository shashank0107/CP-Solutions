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
const int N = 55;

int n, ans;
vector<int> g[N];
bool vis[N];

void pre(){
	for(int i = 0; i < n; i++)	g[i].clear(), vis[i] = false;
	ans = 0;
}

void dfs(int v){
	vis[v] = true;
	int nbcnt = 0;
	for(auto i : g[v])
		if (!vis[i])	dfs(i), nbcnt++;
	if (nbcnt == 0)	ans++;	
}

class CellRemoval {
public:
	int cellsLeft(vector <int> parent, int deletedCell) {
		n = parent.size();
		pre();
		int root=0;
		for(int i = 0; i < n; i++)	if (parent[i] == -1)	root = i;
		vis[deletedCell] = true;
		for(int i = 0; i < n; i++)	if (parent[i] != -1)	g[parent[i]].push_back(i);
		
		if (vis[root])	return 0;
		
		dfs(root);
		
		return ans;
		
	}
};
