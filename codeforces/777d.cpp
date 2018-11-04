#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("777d0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<string> k(n);
	for (auto& s : k) cin >> s;
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < max(k[i].size(), k[i-1].size()); j++) {
			if (k[i-1][j] > k[i][j]) {
				k[i-1].resize(j);
				break;
			} else if (k[i-1][j] < k[i][j]) {
				break;
			}
		}
	}
	copy(k.begin(), k.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}
