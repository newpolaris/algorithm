#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("764b0.in", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	for (int i = 0; i < n/2; i++) {
		if (i % 2 == 0) {
			swap(a[i], a[n-i-1]);
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " \n"[i == n];
}
