#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
ll remaining[101][101];

int main() {
#ifdef _DEBUG
	freopen("758c.in", "r", stdin);
#endif
	ll n, m, x, y, k;
	cin >> n >> m >> k >> x >> y;

	// one period T
	ll T = (n == 1) ? m : n*m + (n-2)*m;
	ll repeat = k / T;
	ll remain = k % T;

	// place remainder
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (remain - 1 >= 0) {
				remaining[i][j] += 1;
				remain--; 
			}
		}
	}
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (remain - 1 >= 0) {
				remaining[i][j] += 1; 
				remain--; 
			}
		}
	}

	auto f = [&](int _y, int _x) {
		ll factor = (_y == 0 || _y == n-1) ? 1 : 2;
		ll ret = repeat * factor;
		return ret + remaining[_y][_x];
	};

	auto maxV = max(max(f(0, 0), f(1, 0)), f(n-2, 0));
	auto minV = f(n-1, m-1);
	
	cout << maxV<< " " << minV << " " << f(y-1, x-1) << endl;
}
