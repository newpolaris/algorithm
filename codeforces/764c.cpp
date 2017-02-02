#include <iostream>
#include <vector>
#include <map>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("764c0.in", "r", stdin);
#endif
	int n, a, b;
	cin >> n;
	vector<pair<int, int>> link(n);
	for (auto& l : link)
		cin >> l.x >> l.y;
	vector<int> color(n);
	for (auto& c : color) cin >> c;

	vector<pair<int, int>> rootcandi;

	map<int, int> cnt;
	for (auto& l : link) {
		if (color[l.x] != color[l.y]) {
			cnt[l.x] += 1;
			cnt[l.y] += 1;
		}
	}
	vector<int> root;
	for (auto& c : cnt) {
		if (c.y > 1)
			root.push_back(c.x);
	}
	if (root.size() == 1) {
		cout << "YES" << endl;
		cout << root[0] << endl;
	} else {
		cout << "NO" << endl;
	}
}
