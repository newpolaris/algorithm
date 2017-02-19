#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	auto p = minmax_element(a.begin(), a.end());
	cout << (*p.first * *p.second) << endl;

	return 0;
}
