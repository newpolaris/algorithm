#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <queue>
#include <cctype>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))
#define x first
#define y second 

using namespace std;

int type(char c) {
	if (isdigit(c)) return 0;
	if (isalpha(c)) return 1;
	return 2;
}

int main() {
#ifdef _DEBUG
	freopen("761c0.in", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	vector<string> pass(n);
	for (auto& s : pass) cin >> s;
	vector<vector<pair<int,int>>> typeDist(3);
	REP(i, 0, n) {
		REP(j, 0, m) {
			int dist = min(j, m - j);
			typeDist[type(pass[i][j])].push_back({dist, i});
		}
	}
	REP(i, 0, 3) sort(ALL(typeDist[i]));
	int minDist = m*n;
	for (auto i : typeDist[0]) {
		for (auto j : typeDist[1]) {
			if (i.y == j.y) continue;
			for (auto k : typeDist[2]) {
				if (j.y == k.y || i.y == k.y) continue;
				minDist = min(minDist, i.x + j.x + k.x);
			}
		}
	}
	cout << minDist << endl;
}
