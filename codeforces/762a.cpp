#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
#ifdef _DEBUG
	freopen("762a.in", "r", stdin);
#endif
	ll n, k;
	cin >> n >> k;

	vector<ll> l;
	for (ll a = 1; a*a <= n; a++) {
		if (n % a == 0) {
			l.push_back(a);
			if (n/a != a)
				l.push_back(n/a);
		}
	}
	sort(l.begin(), l.end());
	cout << (l.size() >= k ? l[k-1] : -1) << endl;

	return 0;
}
