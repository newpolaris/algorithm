#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <string.h>
#include <regex>
#include <iterator>

#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define irep(i, a, b) for (int i = (a)-1, i##_end_ = (b); i >= i##_end_; --i)

using namespace std;

template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; rep(i, 0, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }

// tag: Fail, fail, dp
int main() {
#ifdef _DEBUG
	freopen("1563.in", "r", stdin);
#endif
	int n;
	cin >> n;
	static int mod = 1e6;
	static int cache[1002][2][3];
	memset(cache[1], 0, sizeof(cache[1]));
	cache[1][0][0] = 1;
	cache[1][0][1] = 1;
	cache[1][1][0] = 1;
	for (int i = 2; i <= n; i++) {
		// normal case가 나올 경우
		for (int l = 0; l < 2; l++)
		for (int a = 0; a < 3; a++)
			cache[i][l][0] = (cache[i-1][l][a] + cache[i][l][0]) % mod;

		// 추가 지각 가능한 경우
		for (int a = 0; a < 3; a++)
			cache[i][1][0] = (cache[i-1][0][a] + cache[i][1][0]) % mod;

		// 결석 가능한 경우
		for (int l = 0; l < 2; l++)
		for (int a = 0; a < 2; a++)
			cache[i][l][a+1] = (cache[i-1][l][a] + cache[i][l][a+1]) % mod;
	}
	int tot = 0;
	for (int l = 0; l < 2; l++)
	for (int a = 0; a < 3; a++)
		tot = (tot + cache[n][l][a]) % mod;
	cout << tot << endl;

	return 0;
}
