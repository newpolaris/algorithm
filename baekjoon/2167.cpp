#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("2167.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int a[300][300];
	forn (i, 0, n) forn (j, 0, m) cin >> a[i][j];
	// 0번째 칸을 추가하여 코드를 단순히 한다
	int c[301][301];
	memset(c, 0, sizeof(c));
	/*
	 * 2D에서 양쪽 증가는 불가능하다. 오른쪽 증가, 아래로는 그냥 바로위의 sum을 취한다
	 * | a b | 
	 * | c d | 
	 * d = ba + ca - aa + d'
	 * d' 는 matrix 값
	 */
	forn (i, 1, n+1)
		forn (j, 1, m+1)
			c[i][j] = c[i-1][j] + c[i][j-1] + a[i-1][j-1] - c[i-1][j-1];
	auto sum = [&](int sx, int sy, int ex, int ey) {
		return c[ey][ex] - c[ey][sx-1] - c[sy-1][ex] + c[sy-1][sx-1];
	};
	
	int k;
	cin >> k;
	while (k--) {
		int sx, sy, ex, ey;
		cin >> sy >> sx >> ey >> ex;
		cout << sum(sx, sy, ex, ey) << endl;
	}
	
	return 0;
}
