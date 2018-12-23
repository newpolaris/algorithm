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

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("752b.in", "r", stdin);
#endif
	string type, display;
	cin >> type >> display;
	vector<pair<char, char>> fixlist;
	auto check = [&]() -> bool {
		map<char, char> maping;
		REP(i, 0, type.size()) { 
			auto t = type[i];
			auto d = display[i];
			if (t > d)
				swap(t, d);
			auto k = maping.find(t);
			auto q = maping.find(d);
			if (k != maping.end() && k->second != d)
				return false;
			if (q != maping.end() && q->second != t)
				return false;
			if (t != d && k == maping.end()) {
				fixlist.push_back({t, d});
			}
			maping[t] = d;
			maping[d] = t;
		}
		return true;
	};
	if (check()) {
		cout << fixlist.size() << endl;
		for (auto f : fixlist)
			cout << f.first << " " << f.second << endl;
	} else {
		cout << - 1 << endl;
	}

	return 0;

}
