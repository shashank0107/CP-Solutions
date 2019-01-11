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

// Debug //

#define trace(x)                 cout << #x << ": " << x << endl;
#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;



bool valid(string& s){
	int cnt = 0;
	for(auto i : s){
		if (i=='X')	cnt++;	else cnt--;
		if (cnt < 0)	return false;
	}
	return cnt==0;	
}

class DyckwordUniformer {
public:
	string uniform(string s) {
		
		vector<string> dk;
		int n = s.size();
		if (!valid(s)) return "";
		
		bool change = true;
		
		while(change)
		{
			change = false;
		for(int e = n-1; e >= 0; e--)
		{
			// find the first dyck string ending at e
			int cnt = 0, st = e;
			bool isdyck = false;
			for(st = e; st >= 0; st--){
				if (s[st] == 'X')	cnt++;	else cnt--;
				if (cnt > 0)	break;
				if (cnt == 0){	isdyck = true; break;	}
			}
			if (isdyck)
			{
				// check if it should be swapped with the next dyck
				int e2 = st-1, st2;
				bool found = false;
				for(st2 = e2; st2 >= 0; st2--){
					if (s[st2] == 'X')	cnt++;	else cnt--;
					if (cnt>0)	break;
					if (cnt == 0){	found = true; break;	}
				}
				
				if (found)
				{
					//trace2(st, e);
					//trace2(st2, e2);
					string t2 = s.substr(st, e-st+1);
					string t1 = s.substr(st2, e2-st2+1);
					int len2 = t2.size();
					int len1 = t1.size();
					//trace2(t1, t2);
					if (t2 < t1)
					{
						int c = 0;
						for(int k = st2; k < st2+t2.size(); k++)
							s[k] = t2[c++];
						//trace(s);
						change = true;
						c = 0;
						for(int k = st2+t2.size(); k < st2+len1+len2; k++)
							s[k] = t1[c++];
						//trace(s);
					}
				}			
			}
		
		}
		
		}
		
		return s;
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
