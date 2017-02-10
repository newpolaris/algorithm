#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <queue>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

string a, b;

int main() {
#ifdef _DEBUG
	freopen("766b0.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	sort(ALL(a), greater<int>());
	for (int i = 0; i < (int)a.size() - 2; i++) {
		if (a[i] < a[i+1]+a[i+2]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
