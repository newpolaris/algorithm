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
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(w-x, x), min(h-y, y)) << endl;
	return 0;
}
