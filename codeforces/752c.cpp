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
	freopen("752c1.in", "r", stdin);
#endif
	int n;
	cin >> n; 
	string path;
	cin >> path;
	// L, R, U, D
	map<char, int> idx = { {'L', 0}, {'R', 1}, {'U', 2}, {'D', 3} };
	vector<pair<int, int>> dir = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	// last element
	int cnt = 1;
	pair<int, int> curPos = {0, 0};
	pair<int, int> lastPos = {0, 0};
	int moveDist = 0;
	auto dist = [](pair<int, int> p) {
		return abs(p.x) + abs(p.y);
	};
	for (int i = path.size(); i > 0; i--) {
		auto d = dir[idx[path[i-1]]];
		decltype(curPos) nextPos;
		nextPos.x = curPos.x - d.x;
		nextPos.y = curPos.y - d.y;
		moveDist++;
		auto dk = dist({lastPos.x - nextPos.x, lastPos.y - nextPos.y});
		if (dk < moveDist) {
			cnt++;
			lastPos = curPos;
			moveDist = 1;
		}
		curPos = nextPos;
	}
	cout << cnt << endl;
	return 0;
}
