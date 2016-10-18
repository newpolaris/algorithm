#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std; 

int main() {
#ifdef _DEBUG
	freopen("732b.in", "r", stdin);
#endif

	int n, k;
	cin >> n >> k;

	vector<int> L(n);
	for (auto& l : L)
		cin >> l;
	auto LO = L;
	if (n == 1) {
		L.front() += max(0, k - L.front());
	} else {
		for (int i = 1; i < n; i++) {
			L[i] += max(0, k - (L[i-1] + L[i]));
		}
	}
	int diff = 0;
	for (int i = 0; i < n; i++)
		diff += L[i] - LO[i];
	cout << diff << endl;
	for (int i = 0; i < n; i++)
		cout << L[i] << " ";
	cout << endl;

	return 0;
}
