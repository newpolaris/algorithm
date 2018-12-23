#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <string.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("779a0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k, n;
	string str;
	cin >> str >> k;
	n = stoll(str);
	if (n == 0) {
		cout << 0 << endl;
	} else {
		int cnt = count_if(str.begin(), str.end(), [](char c) { return c == '0';});
		if (cnt < k) {
			cout << (int(str.size()) - 1) << endl;
		} else {
			int cnt = 0, zcnt = 0;;
			int i = str.size() - 1;
			while (i >= 0 && zcnt < k) {
				if (str[i] == '0') {
					zcnt++;
				} else {
					cnt++;
				}
				i--;
			}
			cout << cnt << endl;
		}
	}
	return 0;
}
