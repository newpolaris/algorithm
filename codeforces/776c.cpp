#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>

#define all(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))

using namespace std;

using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("776c0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);

	/*
	 * Fail: sum이 power of k가 되야 한다는 걸 이렇게 쓸수 도 있다
	 * 수식 변형, map 을 통한 binary serach, reverse n iter
	 * 기억해야할 기법이 많이 나옴
	 * p[r] - p[l-1] = w
	 * 단순히 생각하면 n^2 serach
	 * 구간이 아니라, p[r]을 다른 pointer, 즉 two pointer라 치면,
	 * l <= r 일 때, p[r]은 단순한 값이고, 
	 * l이 고정되고 w 가 변화할 때 p[r]의 counting 수만 구하면 됨
	 */

	int n, k;
	scanf("%d%d", &n, &k);
	ll p[n+1];
	p[0] = 0;
	forn (i, 0, n) 
		scanf("%lld", &p[i+1]);
	partial_sum(p, p+n+1, p);

	ll ans = 0;
	map<ll, int> counter;
	if (k == 1) {
		for (int l = n; l >= 0; l--) {
			counter[p[l]]++;
			ans += counter[p[l]+1];
		}
	} else if (k == -1) {
		for (int l = n; l >= 0; l--) {
			counter[p[l]]++;
			ans += counter[p[l]+1];
			ans += counter[p[l]-1];
		}
	} else {
		map<ll, int> counter;
		for (int l = n; l >= 0; l--) {
			ll w = 1;
			// 특정수가 몇개냐 => p[l]+w 이 해당 수일 때 개수를 더하면 된다.
			counter[p[l]]++;
			// w를 변경, counter를 누적
			while (true) {
				if (abs(w) >= 1e15) break;
				auto r = p[l] + w;
				/*
				 * 계속 추가되므로 존재 검사하면 더 빨라지겠지
				 * 그냥 cin 과 아래 검사가 없으면 time over at 72
				 */
				if (counter.count(r) > 0)
					ans += counter[r];
				w *= k;
			}
		}
	}
	printf("%lld\n", ans);

	return 0;
}
