#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
#ifdef _DEBUG
	freopen("764a0.in", "r", stdin);
#endif
	int n, m, z;
	cin >> n >> m >> z;
	int c = 0;
	auto k = gcd(n, m);
	auto q = k * (m / k) * (n / k);
	auto t = q;
	while (t <= z) {
		t += q;
		c++;
	}
	cout << c << endl;
	return 0;
}
