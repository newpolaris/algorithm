#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int t, n, r;	
	cin >> t;

	// 0 처리가 귀찬다: nCr = n!/(n-r)!/r! and (0)! = 1, int overflow
	// dp로 계산한다: 2개를 두고 반복적으로 계산한다
	int c[2][31];
	while (t-- ) {
		cin >> r >> n;
		c[0][0] = c[1][0] = c[1][1] = 1;
		for (int i = 2; i <= n; i++) {
			// 현재 계산해야 할 index, 이전 index
			auto k = i%2, pk = (i-1)%2;
			// 기본값을 채우고
			c[k][0] = c[k][i] = 1;
			// (i,j) = (i-1,j-1) + (i-1,j)
			for (int j = 1; j < i; j++) c[k][j] = c[pk][j-1]+c[pk][j];
		}
		cout << c[n%2][r] << endl;
	}
	return 0;
}
