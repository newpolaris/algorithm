#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>

using namespace std;

int main() {
#ifdef _DEBUG
#endif
	ios::sync_with_stdio(0);
	int n = 9;
	vector<int> arr(n);
	for (auto& a : arr) cin >> a;
	sort(arr.begin(), arr.end());
	vector<int> k = { 0, 0, 1, 1, 1, 1, 1, 1, 1 };
	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (k[i]) sum += arr[i];
		}
		if (sum == 100) break;
	} while (next_permutation(k.begin(), k.end()));

	for (int i = 0; i < n; i++) {
		if (k[i]) cout << arr[i] << endl;
	}

	return 0;
}
