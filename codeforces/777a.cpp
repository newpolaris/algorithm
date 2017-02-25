#include <iostream>
#include <queue>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("777a0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	n %= 6;
	vector<int> shell = { 0, 1, 2 };
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			swap(shell[0], shell[1]);
		} else {
			swap(shell[1], shell[2]);
		}
	}
	cout << shell[x] << endl;;

	return 0;
}
