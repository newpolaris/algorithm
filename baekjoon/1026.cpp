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
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for (auto& a : A) cin >> a;
	for (auto& b : B) cin >> b;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i]*B[n-i-1];
	}
	cout << sum << endl;

	return 0;
}
