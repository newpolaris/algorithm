#include <iostream>
#include <vector>
#include <map>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("760b1.in", "r", stdin);
#endif
	int n, m, k;
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	k--;
	int l = k, c = k, r = k;
	int height = 1;
	int used = n;
	int prev_usage = 0;

	while (used < m) {
		if (l-1 >= 0) l--;
		if (r+1 < n) r++;
		int usage = k-l;
		usage += 1;
		usage += r-k;
		if (prev_usage < usage) {
			height++;
			prev_usage = usage;
			used += usage;
		}
		else {
			auto t = (m - used) / usage;
			height += t;
			used += usage * t;
			if (t == 0) prev_usage = 0;
		}
	}
	cout << height << endl;
}
