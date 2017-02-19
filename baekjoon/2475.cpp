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
	vector<int> a(5);
	for (auto& i : a) cin >> i;
	for_each(a.begin(), a.end(), [](int& k) { k = k*k; });
	cout << (accumulate(a.begin(), a.end(), 0) % 10) << endl;
	return 0;
}
