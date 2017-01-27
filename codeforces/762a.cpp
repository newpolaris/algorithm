#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
#ifdef _DEBUG
#endif
	ll n, k;
	cin >> n >> k;

	vector<ll> l;
	for (ll a = 1; a <= sqrt(n); a++) {
		if (n % a == 0) {
			l.push_back(a);
			l.push_back(n/a);
		}
	}
	sort(l.begin(), l.end());
	vector<ll> div(l.begin(), unique(l.begin(), l.end()));
	cout << (div.size() >= k ? div[k-1] : -1) << endl;

	return 0;
}
