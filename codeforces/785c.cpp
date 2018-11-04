#include <iostream>
#include <map>
#include <algorithm>
#include <cstdint>

#define x first
#define y second

using namespace std;
using ll = int64_t;

int main() {
#ifdef _DEBUG
	freopen("785c0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;

	auto check = [&](ll d) {
		auto p = d - 1;
		auto k = n - (p - m + 1)*(m + p)/2 + (p - m + 1)*m;
		return k - d <= 0;
	};
	ll lo = m, hi = n;
	while (lo < hi) {
		auto k = lo + (hi - lo) / 2;
		if (check(k)) 
			hi = k;
		else
			lo = k + 1;
	}
	cout << lo << endl;
	return 0;
}
