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

int main() {
#ifdef _DEBUG
	freopen("750c0.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& i : a) 
		cin >> i;
	if (n >= k) {
		sort(ALL(a), greater<int>());
	}


	return 0;
}
