#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))
#define x first
#define y second

using namespace std;

using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("767b1.in", "r", stdin);
#endif
	ll s, e, t;
	int n;
	cin >> s >> e >> t;
	cin >> n;
	vector<ll> minute(n);
	for (auto& m : minute) cin >> m;

	vector<ll> candi;
	for (auto c : minute) {
		if (c+t > e) continue;
		candi.push_back(c-1);
		candi.push_back(c);
		candi.push_back(c+t);
	}
	candi.erase(unique(ALL(candi)), candi.end());

	ll minM = -1;
	ll minW = 1e12;

	map<ll, int> counter;
	for (auto c : candi) counter[c] = 1;
	for (auto c : minute) counter[c] += 2;
	ll last = s;
	for (auto p : counter) {
		ll m = p.x;
		int flag = p.y;

		if (flag & 2)
			last += t;
		if (flag & 1) {
			ll w;
			if (m < s)
				w = last - m;
			else 
				w = max(last - m, 0LL);

			if (w < minW) {
				minW = w;
				minM = m;
			}
		}
	}
	cout << minM << endl;

	return 0;
}
