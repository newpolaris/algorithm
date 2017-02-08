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

int main() {
#ifdef _DEBUG
	freopen("750c0.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n, c, d;
	cin >> n;
	vector<pair<int, int>> rates(n);
	for (auto& r : rates)
		cin >> r.x >> r.y;
	const int inf = 987654321;
	int r[2] = {-inf, -inf};
	r[rates[0].y-1] = 0;
	int cur = 0;
	REP(i, 0, n-1) {
		int x0 = rates[i].x;
		int y0 = rates[i].y, y1 = rates[i+1].y;
		cur += x0;
		int& r1 = r[y1-1];
		if (y1 == 1)
			r1 = min(r1, cur);
		else
			r1 = min(r1, cur);
	}
	if (r[0] <= r[1]) {
		cout << "Impossible" << endl;
	} else if (r[0] == inf) {
		cout << 1899 << endl;
	} else if (r[1] == -inf) {
		cout << "Infinity" << endl;
	} else {
		cout << r[0] << " " << r[1] << " " << cur << endl;
		auto r0 = abs(r[0]), r1 = abs(r[1]);
		int s;
		if (r0 > r1) {
			s = 1899-r0+cur+rates[n-1].x;
		} else {
			s = 1899-r0+cur+rates[n-1].x;
		}
		cout << s << endl;
	}
	return 0;
}
