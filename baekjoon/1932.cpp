#include <iostream>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

// tag: dp
int main() {
	int c[501][501], t[501][501];
	int n;
	ios::sync_with_stdio(0);
	cin >> n;
	forn(i, 0, n) forn(j, 0, i+1) cin >> t[i][j];
	// 위에서 내려온다
	c[0][0] = t[0][0];
	auto get = [&](int i, int j) {
		if (j < 0 || j > i+1) return 0;
		return c[i][j];
	};
	int g = 0;
	forn(i, 1, n) {
		forn(j, 0, i+1) c[i][j] = 0;
		forn(j, 0, i+1) {
			c[i][j] = t[i][j] + max(get(i-1,j-1), get(i-1,j));
			g = max(c[i][j], g);
		}
	}
	cout << g << endl;
	
	return 0;
}
