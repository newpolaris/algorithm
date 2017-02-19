#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	ios::sync_with_stdio(0);
	vector<int> c(3);
	for (auto& i : c) cin >> i;
	sort(c.begin(), c.end());
	cout << c[1] << endl;
	return 0;
}
