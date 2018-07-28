#include <iostream>
#include <map>
#include <algorithm>

#define x first
#define y second

using namespace std;
using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("785c1.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	// maximum increase
	auto nn = min(n, m);

	ll sum = n;
	ll i; 
	for (i = nn; i <= 1e18; i++) {
		sum = min(n, sum+nn);
		sum -= i;
		if (sum <= 0) break;
		if (sum + nn <= n) break;
	}
	auto check = [&](ll d) {
		ll p = (d-nn);
		return 2*(sum + p*nn) <= d*(d+1)/2 - nn*(nn+1)/2;
	};
	ll lo = nn, hi = 1e9;
	while (lo < hi) {
		auto m = lo + (hi - lo) / 2;
		if (check(m)) 
			hi = m;
		else
			lo = m + 1;
	}
	cout << lo << endl;
	return 0;
}
