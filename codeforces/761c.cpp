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
	vector<vector<int>> typeDist(3, vector<int>(m, n));
	REP(i, 0, n) {
		REP(j, 0, m) {
			int dist = min(j, m - j);
			int t = type(pass[i][j]);
			typeDist[t][i] = min(dist, typeDist[t][i]);
		}
	}
	int minDist = m*n;
	REP(i, 0, typeDist[0].size()) {
		REP(j, 0, typeDist[1].size()) {
			if (i == j) continue;
			REP(k, 0, typeDist[2].size()) {
				if (j == k || i == k) continue;
				minDist = min(minDist, typeDist[0][i] + typeDist[1][j] + typeDist[2][k]);
			}
		}
	}
	cout << minDist << endl;
}
