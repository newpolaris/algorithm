#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	int k;
	cin >> k;
	int p0 = k/10;
	int p1 = k%10;
	int p = p0;
	int r = p1;
	/*
	 * 01, 11, 12, 23, 35, 58, 83, 31, 14, ...
	 */
	for (int i = 1; i <= 200; i++) {
		p = (p+r)%10;
		swap(r, p);
		if (p0 == p && r == p1) {
			cout << (i) << endl;
			return 0;
		}
	}
	return 0;
}
