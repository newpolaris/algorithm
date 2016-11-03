#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

using Tp = tuple<int, int, int>;

int main() {
#ifdef _DEBUG
	freopen("laser.in", "r", stdin);
#endif
	int t, n, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> in(n);
		for (auto & i : in)
			cin >> i.first >> i.second;
		map<Tp, int> lines;
		for (int i = 0; i < n; i++) {
			for (int k = i + 1; k < n; k++) {
				auto &p = in[i], &q = in[k];
				int a = q.second - p.second;
				int b = p.first - q.first;
				int c = p.first * q.second - q.first * p.second;
				int g = gcd(a, gcd(b, c));
				lines[make_tuple(a/g, b/g, c/g)]++;
			}
		}
		auto cnt = count_if(lines.begin(), lines.end(), 
				[&](const pair<Tp, int>& k) { return k.second >= 5*4/2;});
		cout << cnt << endl;
	}

	return 0;
}
