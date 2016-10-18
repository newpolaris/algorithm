#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("732a.in", "r", stdin);
#endif

	int k, r;
	cin >> k >> r;
	for (int i = 1; i < 100000000; i++) {
		if ((k * i - r) % 10 == 0 || (k * i) % 10 == 0) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
