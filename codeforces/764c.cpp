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
    ios_base::sync_with_stdio(false);
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
		if (c.y > 0)
			rootcandi.push_back(c.x);
	}
	if (rootcandi.size() <= 0)
		rootcandi.push_back(link[0].x);

	int root = -1;	
	for (auto r : rootcandi) { 
		bool bCorrect = true;
		for (auto& l : link) {
			if (color[l.x] != color[l.y]) {
				if (l.x == r || l.y == r) continue;
				else {
					bCorrect = false;
					break;
				}
			}
		}
		if (bCorrect) {
			root = r;
		}
	}
	if (root != -1) {
		cout << "YES" << endl;
		cout << (root+1) << endl;
	} else {
		cout << "NO" << endl;
	}
}
