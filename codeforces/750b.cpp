#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

bool check() {
	int n, t;
	cin >> n;
	string d;
	const int start = 20000;
	int cur = 20000;
	map<string, int> dir = { 
		{"South", -1},
		{"East", 0},
		{"West", 0},
		{"North", 1}};
	while (n--) {
		cin >> t >> d;
		int k = dir[d];
		int next = cur + k*t;
		if (next < 0 || next > start) 
			return false;
		if (cur == start || cur == 0)
			if (next == cur) 
				return false;
		cur = next;
	}
	if (cur != start) 
		return false;
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("750b2.in", "r", stdin);
#endif
	cout << (check() ? "YES" : "NO") << endl;

	return 0;
}
