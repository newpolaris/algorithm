#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <string.h>
#include <regex>
#include <iterator>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int actor[1001][1001];
int main() {
#ifdef _DEBUG
	freopen("729b0.in", "r", stdin);
#endif
	int n, m;
	ios::sync_with_stdio(0);
	cin >> n >> m;
	forn (i, 0, n) forn (j, 0, m) cin >> actor[i][j];

	int cnt = 0;
	bool bBound = false;
	forn (i, 0, n) {
		bBound = false;
		forn (j, 0, m) {
			if (actor[i][j]) bBound = true;
			if (bBound && actor[i][j] == 0) cnt++;
		}
		bBound = false;
		for (int j = m-1; j >= 0; --j) {
			if (actor[i][j]) bBound = true;
			if (bBound && actor[i][j] == 0) cnt++;
		}
	}

	forn (i, 0, m) {
		bBound = false;
		forn (j, 0, n) {
			if (actor[j][i]) bBound = true;
			if (bBound && actor[j][i] == 0) cnt++;
		}
		bBound = false;
		for (int j = n-1; j >= 0; --j) {
			if (actor[j][i]) bBound = true;
			if (bBound && actor[j][i] == 0) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
