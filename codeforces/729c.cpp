#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <string.h>
#include <regex>
#include <iterator>
#include <map>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))
#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("729c4.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);

	int n, k, s, t, v, c;
	cin >> n >> k >> s >> t;
	map<int, int> ct;
	forn (i, 0, n) { 
		cin >> c >> v;	
		ct[c] = max(ct[c], v);
	}
	vector<int> gas(k);
	forn (i, 0, k) cin >> gas[i];

	gas.insert(gas.begin(), 0);
	gas.push_back(s);
	sort(ALL(gas));

	// ct 정리, 계속 증가 함수로 변경
	int maxV = 0;
	for (auto& c : ct) {
		// 가성비가 부족하면 제거한다
		if (c.y <= maxV)
			c.y = 0;
		maxV = max(c.y, maxV);
	}

	vector<int> cost, tank;
	for (auto& c : ct) {
		if (c.y == 0) continue;
		cost.push_back(c.x);
		tank.push_back(c.y);
	}
	auto bestDrive = [&](double dist, double tank) {
		/*
		 * 기름
		 * tank = time*2.0 + (dist-time);
		 * tank - dist = time
		 */
		double acceltime = tank - dist;
		if (acceltime < 0) return -1.0;
		// 거리
		acceltime = min(acceltime, dist);
		return acceltime*1.0 + (dist - acceltime)*2.0;
	};

	// binary search
	auto l = 0, r = sz(cost) - 1;
	auto test = [&](int m) {
		int liter = tank[m];
		double delay = 0.0;
		int go = 0;
		for (int i = 0; i < sz(gas)-1; i++) {
			double dist = gas[i+1] - gas[i];
			double k = bestDrive(dist, liter);
			if (k < 0) return false;
			delay += k;
			go += dist;
		}
		return (delay <= t);
	};
	while (l < r) {
		int m = l + (r - l)/2;
		if (test(m)) 
			r = m;
		else
			l = m+1;
	}
	if (!test(l))
		cout << -1 << endl;
	else
		cout << cost[l] << endl;

	return 0;
}
