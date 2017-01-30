#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
ll mat[101][101];

int main() {
#ifdef _DEBUG
	freopen("758c.in", "r", stdin);
#endif
	ll n, m, x, y, k;
	cin >> n >> m >> k >> x >> y;
	ll N = n+n-1-1;
	if (n == 1) N = 1;
	if (n == 2) N = 2;
	ll basec = k / (N*m);
	ll r = k % (N*m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n-1)
				mat[i][j] = basec;
			else
				mat[i][j] = basec*2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (r - 1 >= 0) { mat[i][j] += 1; r--; }
		}
	}
	for (int i = n-2; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			if (r - 1 >= 0) { mat[i][j] += 1; r--; }
		}
	}

	ll minV = numeric_limits<ll>::max();
	ll maxV = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			minV = min(minV, mat[i][j]);
			maxV = max(maxV, mat[i][j]);
		}
	}

	
	cout << maxV<< " " << minV << " " << mat[x-1][y-1] << endl;
}
