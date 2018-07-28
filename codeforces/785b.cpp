#include <iostream>
#include <map>
#include <algorithm>

#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("785b1.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b;
	int inf = 1e9;
	int p[2][2] = {
		{ 1, inf },
		{ 1, inf },
	};
	for (int i = 0; i < 2; i++) {
		cin >> n;
		while (n--) {
			cin >> a >> b;
			p[i][0] = max(p[i][0], a);
			p[i][1] = min(p[i][1], b);
		}
	}
	int maxp = max(p[1][0] - p[0][1], p[0][0] - p[1][1]);
	cout << max(0, maxp) << endl;
	return 0;
}
