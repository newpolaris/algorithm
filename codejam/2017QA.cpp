#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
#ifdef _DEBUG
	freopen("2017QA.in", "r", stdin);
#else
	freopen("2017QA.in0", "r", stdin);
	freopen("2017QA.out0", "w", stdout);
#endif
	int T, k;
	string str;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> str >> k;
		int cnt = 0;
		for (int i = 0; i <= str.size() - k; i++) {
			if (str[i] == '+') continue;
			cnt++;
			for (int j = 0; j < k; j++) {
				if (str[j+i] == '+')
					str[j+i] = '-';
				else
					str[j+i] = '+';
			}
		}
		bool done = all_of(str.begin(), str.end(), [](char c) { return c == '+'; });
		cout << "Case #" << t << ": ";
		if (done) cout << cnt << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
