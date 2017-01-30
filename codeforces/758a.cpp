#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("758a.in", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& a : A)
		cin >> a;
	int g = *max_element(A.begin(), A.end());
	int t = 0;
	for (auto a : A) {
		t += g - a;
	}
	cout << t << endl;
}
