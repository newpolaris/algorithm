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
	priority_queue<pair<int, pair<int, int>>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int dist = min(j, m - j);
			que.push({dist, {0, type(pass[i][j])}});	
		}
	}

}
