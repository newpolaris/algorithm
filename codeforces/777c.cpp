#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("777c.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, l, r, k;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	// last range
	vector<int> la(n, n-1);

	for (int i = 0; i < m; i++) {
		int last = n-1;
		int mx = mat[n-1][i];
		for (int j = n-1; j >= 0; j--) {
			if (mat[j][i] > mx) {
				mx = mat[j][i];
				la[last] = min(j+1, la[last]);
				last = j; 
			}
			mx = min(mat[j][i], mx);
		}
		la[last] = 0;
	}
	int mx = la[n-1];
	for (int i = n - 1; i >= 0; i--) {
		mx = la[i] = min(la[i], mx);
	}
	cin >> k;
	while (k--) {
		cin >> l >> r;
		l--, r--;
		cout << (la[r] <= l ? "Yes" : "No") << endl;
	}
	return 0;
}
