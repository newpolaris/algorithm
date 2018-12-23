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

#define all(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))
#define x first
#define y second

using namespace std;

/*
 * 처음에 속도가 주어진걸로 착각한 것도 문제지만,
 * 탱크 용량으로 배열을 생성할 필요가 없다.
 * 최소의 탱크 용량을 찾은 후 그냥 차 목록에서 선택하면 된다.
 * 그러면 차 목록을 항상 증가하게 수정할 필요도 없으며,
 * 단순해 진다
 */
int main() {
#ifdef _DEBUG
	freopen("729c3.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);

	int n, k, s, t;
	cin >> n >> k >> s >> t;
	vector<pair<int, int>> car(n);
	forn (i, 0, n) cin >> car[i].x >> car[i].y;
	vector<int> gas(k);
	forn (i, 0, k) cin >> gas[i];

	gas.insert(gas.begin(), 0);
	gas.push_back(s);
	sort(all(gas));

	// binary search
	int l = 0, r = 1e9;
	auto test = [&](int liter) {
		double delay = 0.0;
		for (int i = 0; i < sz(gas)-1; i++) {
			int dist = gas[i+1] - gas[i];
			// 도착 못한다
			if (liter - dist < 0) return false;
			// fast mode는 단순 min(x, f-x) 로 구할 수 있다. 
			// 오래 걸릴게 아니다
			auto fast = min(liter - dist, dist);
			auto slow = dist - fast;
			delay += fast + slow*2;
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
	int i = -1;
	if (test(l)) {
		sort(all(car));
		for (auto& c : car) {
			if (c.y	>= l) {
				i = c.x;
				break;
			}
		}
	}
	cout << i << endl;

	return 0;
}
