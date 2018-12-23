#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
#ifdef _DEBUG
	freopen("2017QB.in", "r", stdin);
#else
	freopen("2017QB.in0", "r", stdin);
	freopen("2017QB.out0", "w", stdout);
#endif
	int T;
	string num;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> num;
		int n = num.size();
		for (int i = n-1; i >= 1; i--) {
			if (num[i-1] <= num[i]) continue;
			num[i-1] = num[i-1] - 1;
			for (int k = i; k < n; k++) {
				num[k] = '9';
			}
		}
		int st = 0;
		for (int i = 0; i < n; i++) {
			if (num[i] == '0') st++;
			else break;
		}
		cout << "Case #" << t << ": ";
		cout << string(num.begin()+st, num.end()) << endl;
	}
	return 0;
}
