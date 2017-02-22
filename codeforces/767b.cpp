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
	freopen("767b2.in", "r", stdin);
#endif
	ll s, e, t;
	int n;
	cin >> s >> e >> t;
	cin >> n;
	vector<ll> a(n);
	for (auto& m : a) cin >> m;
	
	/* Fail: 
	 * 10^12 중 어느 시간에 도착해야 기다리는게 적을까?
	 * 양방향, 단방향 아니니 binary 는 못쓸꺼고;
	 * 사이에 끼어넣는 연산을 기술하지 못함.
	 * 가능 조건을 n-1, n, n+t 로 만 봄.
	 *
	 * 사람에 관해 식을 새울 수 있을 듯. 식을 a, b로 분리시키기. 구조적으로 짜기
	 *
	 * a_i 도착 시간, b_i 서비스 받기 시작 시간
	 * b_i - (a_i - 1) 이 최소 대기 시간 (즉, 다른사람 오기 1분전 이 모든 경우 최적임)
	 * a_i > b_i-1 + t 이라면 대기시간 0
	 *
	 *  b1     t     b2
	 *  | ---------- |
	 *  a1  a2
	 *
	 *  min waiting : b2 - (a2-1)
	 *
	 *  b1     t         b2
	 *  | ----------|--- |
	 *  a1               a2
	 *
	 *  min waiting : min(b1 + t - (a2-1), 0)
	 *
	 *  위의 식은 통합 가능하지만 문제는 시간 안에 종료 확인하려면
	 *  a2-1 로는 부족함.
	 *
	 *  so, case 나눠 작성;
	 *
	 * 문제가 된 것. 
	 *
	 * 1. a_i - 1 + t 가 종료시간보다 작거나 같은지 체크
	 * 2. n == 0
	 * 3. a[1] 이 s보다 클 때
	 */
	if (n == 0) {
		cout << s << endl;
		return 0;
	}
	static ll b[100001];
	b[0] = max(s, a[0]);
	for (int i = 1; i < n; i++)
		b[i] = max(b[i-1] + t, a[i]);

	ll minW, minM;

	// s가 a[0] 보다 작은 경우 음수가 나오지만 실제론 0 이므로 문제 되진 않는다
	minW = s - (a[0] - 1);
	// s와 a[0]의 최소값을 취함으로써 문제3번을 피한다
	minM = min(s, a[0] - 1);

	for (int i = 1; i < n; i++) {
		ll m = a[i] - 1;
		if (a[i] > b[i-1] + t)
			m = b[i-1] + t;
		ll w = b[i-1] + t - m;
		if (m + t <= e && w < minW) {
			minW = w;
			minM = m;
		}
	}
	// 모든 사람들이 다녀간 후에도 시간 남을 경우
	if (b[n-1] + 2*t <= e && 0 < minW) {
		minW = 0;
		minM = b[n-1] + t;
	}
	cout << minM << endl;

	return 0;
}
