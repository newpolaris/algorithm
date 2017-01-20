#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int x[51], y[51];

int main() {
	freopen("1b.in", "r", stdin);
#ifndef _DEBUG
	freopen("1b.out", "w", stdout);
#endif
	int T, N, R;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> R;
		int max_cnt = 0;
		for (int n = 0; n < N; n++)
			cin >> x[n] >> y[n];


		cout << "Case #" << t << ": " << max_cnt << endl;
	}

	return 0;
}
