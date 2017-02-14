#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

bool check(string str) {
	if (str[0] != 'a') 
		return false;
	int idx = 1;
	for (int i = 1; i < str.size(); i++) {
		auto k = (int)str[i]-'a';
		if (k > idx) 
			return false; 
		if (k == idx) idx++;
	}
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("765a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	string str;
	cin >> str;

	cout << (check(str) ? "YES" : "NO") << endl;

	return 0;
}
