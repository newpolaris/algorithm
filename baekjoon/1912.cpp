#include <iostream>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("1912.in", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	/*
	 * LIS 같은데, 어케 풀었지?
	 *
	 * LIS(k) = a[k] + max(0, LIS(k+1))
	 * 대충 되는데?
	 */
	int c[100001], ans = -1000;
	c[n] = 0;
	for (int k = n-1; k >= 0; k--) {
		c[k] = a[k] + max(0, c[k+1]);
		ans = max(ans, c[k]);
	}
	cout << ans << endl;
	return 0;
}
