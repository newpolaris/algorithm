#include <iostream>
#include <queue>
#include <functional>
#include <string.h>

#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("779a0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int score[2][6];
	memset(score, 0, sizeof(score));
	int n, a, b;
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			score[i][a]++;
		}
	}
	bool bSuc = true;
	int cnt = 0;
	for (int i = 1; i < 6; i++) {
		auto diff = score[0][i] - score[1][i];
		if (abs(diff) % 2) {
			bSuc = false;
			break;
		}
		cnt += abs(diff)/2;
	}
	cout << (bSuc ? cnt/2 : -1) << endl;

	return 0;
}
