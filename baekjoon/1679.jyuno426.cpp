#include <bits/stdc++.h>
using namespace std;

int n;

int f(int k) {
	if (k <= n) return n - k;
	if (k == 1) return n + 1;
	if (!(k & 1)) return min(1 + f(k / 2), k - n);
	return 1 + min(f(k - 1), f(k + 1));
}

int main() {
	int k; cin >> n >> k;
	cout << f(k) << endl;
}
