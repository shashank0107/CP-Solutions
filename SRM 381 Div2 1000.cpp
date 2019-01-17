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


bool comp(int a, int b){
	string sa = to_string(a);
	string sb = to_string(b);
	string ab = sa+sb, ba = sb+sa;
	return ab > ba;

}


class TheNumbersLord {
public:
	string create(vector <int> num, int n) {
		
		sort(num.begin(), num.end(), comp);
		//for(auto i : num)	cout << i << " ";cout << endl;
		int ex = n-num.size();
		vector<int> temp = num;
		sort(temp.begin(), temp.end(), greater<int>());
		int x = temp[0];
		//cout << x << endl;
		string ans;
		//for(int i = 0; i < ex; i++)	ans+=to_string(num[0]);
		for(auto i : num){
			ans+=to_string(i);
			if (i == x){	for(int i = 0; i < ex; i++)	ans+=to_string(x);	x = -1;	}
		}
		return ans;
	}
};
