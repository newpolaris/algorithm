#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("a.in", "r", stdin);
#endif

	int k;
	typedef long long ll;
	ll n, m, r0, c0, r, c, A, B;
	cin >> k;
	while (k--) {
		cin >> n >> m >> r0 >> c0 >> r >> c >> A >> B;
		ll r = abs(r - r0);
		ll t = r / A + ((r % A) > 0);
		ll c = abs(c - c0);
		t += c / B + ((c % B) > 0);
		cout << t << endl;
	}

	return 0;
}
