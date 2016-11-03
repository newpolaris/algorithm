#include <iostream>
#include <random>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int gcd2(int a, int b) {
	while (b) {
		auto t = b;
		b = a % b;
		a = t;
	}
    return a;
}

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> GN(-5000, 5000);

#if 0
	int T = 1000;
	while (T--) {
		auto a = GN(gen), b = GN(gen);
		if (gcd2(a, b) != gcd(a, b)) {
			cout << "NOT SAME " << a << " " << b << endl;
		}
	}
#else
	cout << gcd(-10, -15) << endl;
	cout << gcd2(-10, -15) << endl;
#endif
	return 0;
}
