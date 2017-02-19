#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	int c[301][3];
	c[0][0] = 0;
	c[0][1] = c[0][2] = -1e9;
	for (int i = 1; i <= n; i++) {
		c[i][0] = c[i][1] = c[i][2] = -1e9;

		// 1칸 전진
		for (int j = 0; j < 2; j++)
			c[i][j+1] = max(c[i][j+1], a[i-1] + c[i-1][j]);
		if (i - 2 < 0) continue;

		// 2칸 전진 (도착 즉시 1개기 때문에 0개론 못간다
		for (int j = 0; j < 3; j++)
			c[i][1] = max(c[i][1], a[i-1] + c[i-2][j]);
	}
	cout << max(max(c[n][0], c[n][1]), c[n][2]) << endl;
	return 0;
}
