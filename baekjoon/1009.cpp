#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int T, a, b;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		int c = 1;
		for (int i = 0; i < b; i++)
			c = (c * (a%10))%10;
		cout << (c == 0 ? 10 : c) << endl;
	}
	return 0;
}
