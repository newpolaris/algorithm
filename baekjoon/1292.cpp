#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define x first
#define y second 
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int a, b;
	cin >> a >> b;
	auto csum = [](int a) {
		int ret = 0;
		forn (i, 0, 1000) {
			ret += i*min(a, i);
			a -= i;
			if (a <= 0) break;
		}
		return ret;
	};
	cout << (csum(b)-csum(a-1)) << endl;

	return 0;
}
