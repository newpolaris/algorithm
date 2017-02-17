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

int main() {
#ifdef _DEBUG
	freopen("729a1.in", "r", stdin);
#endif
	int n;
	cin >> n;
	string wd;
	cin >> wd;
	int i = 0;
	while (i < n) {
		if (wd.substr(i, 3) == "ogo") {
			i += 3;
			while (wd.substr(i, 2) == "go") {
				i += 2;
			}
			cout << "***";
		} else {
			cout << wd[i];
			i += 1;
		}
	}
	cout << endl;
	return 0;
}
