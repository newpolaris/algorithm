#include <iostream>
#include <vector>
#include <map>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("764c.in", "r", stdin);
#endif
	int n, a, b;
	cin >> n;
	vector<pair<int, int>> link(n-1);
	for (auto& l : link) {
		cin >> a >> b;
		l.x = a - 1;
		l.y = b - 1;
	}
	vector<int> color(n);
	for (auto& c : color) cin >> c;

	map<int, int> cnt;
	for (auto& l : link) {
		if (color[l.x] != color[l.y]) {
			cnt[l.x] += 1;
			cnt[l.y] += 1;
		}
	}
	vector<int> rootcandi;
	for (auto& c : cnt) {
		if (c.y > 1)
			rootcandi.push_back(c.x);
	}
	if (rootcandi.size() <= 0) {
		if (cnt.size() > 0)
			rootcandi.push_back((*cnt.begin()).x);
		else
			rootcandi.push_back(0);
	}
	if (rootcandi.size() == 1) {
		cout << "YES" << endl;
		cout << (rootcandi[0]+1) << endl;
	} else {
		cout << "NO" << endl;
	}
}
