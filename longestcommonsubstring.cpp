/* 
 * http://www.practice.geeksforgeeks.org/problem-page.php?pid=1439
 * Longest Comon Sustring을 DP로 찾는 방법 O(n*m)
 * 단순히, 아래 판별식을 이용한다.
 * LCSuff(x, y, m, n) = LCSuff(x, y, m-1, n-1) + 1 if x[m-1] = y[n-1]
 *                       0  Otherwise (if x[m-1] != y[n-1])
 */
#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

int cache[101][101];
int LCSuff(const string& x, const string& y, int n, int m) {
	if (n < 0 || m < 0) return 0;
	int& ret = cache[n][m];
	if (ret >= 0) return ret;
	return ret = (x[n] == y[m]) ? LCSuff(x, y, n-1, m-1) + 1 : 0;
}

int main() {
#ifdef _DEBUG
	freopen("longestcommonsubstring.in", "r", stdin);
#endif
	int c, n, m;
	string x, y;
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		cin >> x >> y;
		cout << LCSuff(x, y, n-1, m-1) << endl;
	}
}
