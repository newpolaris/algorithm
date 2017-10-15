#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int i = 7, k, sum = 0, minv = 1e8;
	while (i--) {
		cin >> k;
		if (k % 2) {
			sum += k;
			minv = min(minv, k);
		}
	}
	if (sum == 0) cout << -1 << endl;
	else {
		cout << sum << endl << minv << endl;
	}
	return 0;
}
