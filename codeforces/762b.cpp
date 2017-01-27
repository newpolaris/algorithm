#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int main() {
#ifdef _DEBUG
	freopen("762b.in", "r", stdin);
#endif
	ll a, b, c, m, v;
	cin >> a >> b >> c;
	cin >> m;
	vector<pair<int, string>> mouses(m);

	for (auto& m : mouses)
		cin >> m.first >> m.second;

	sort(mouses.begin(), mouses.end());
	ll cnt = 0, total = 0;
	for (auto& m : mouses) {
		if (m.second == "USB" && a > 0) {
			cnt++; a--; total += m.first;
		}
		else if (m.second == "PS/2" && b > 0) {
			cnt++; b--; total += m.first;
		}
		else if (c > 0) {
			cnt++; c--; total += m.first;
		}
	}


	return 0;
}
