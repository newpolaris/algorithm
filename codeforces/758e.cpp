#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <string.h>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

// Ex2) 475 = 1*16^2 + 13*16^1 + 11*16^0 => (11311)
using namespace std;

typedef long long ll;

/*
 * JMB의 PI와 같이 k를 시작지점에서 부터 각각 나눠 각 나뉜 부분을 최적화 시킨다
 */
const ll inf = 1e18;
string n, k;
ll base;

// 10^60 이니 넉넉하게 잡는다.
const int N = 70;
ll cache[N][N];
ll power[N];
/*
 * Grid 도 된다고 한다.
 * 1000/1001 의 경우
 * 1,01,001,1001로 string을 나눌수 있다
 * leading zero, base 보다 큰거 제거하고,
 * base를 곱하며 최소 값을 구하면 된다.
 */
ll memorize(int begin, int b) {
	if (begin >= SZ(k)) return 0;
	auto& ret = cache[begin][b];
	if (ret != -1) return ret;
	ret = inf;
	for (int l = 1; l <= SZ(n); l++) {
		int st = SZ(k)-l-begin;
		if (st < 0) continue;
		auto subnumber = k.substr(st, l);

 		// leading zero 를 제거하고, 그냥 0은 통과해야하니 길이로 체크
		if (subnumber[0] == '0' && subnumber.size() > 1)
			continue;
		ll r = stoll(subnumber);
		// base 보다 큰건 제거
		if (r >= base) continue;

		// 오버플로우가 실제로 문제. 답의 한계가 있으니, 단순히 나누면
		// 곱한 후가 inf를 넘는지 점검 가능하다
		if (r > inf/power[b])
			continue;
		ret = min(ret, memorize(begin+l, b+1) + r * power[b]);
	}
	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("758d5.in", "r", stdin);
#endif
	memset(cache, -1, sizeof(cache));
	cin >> n >> k;
	base = stoll(n);

	// power는 나눠서 계산해 두면 편하다
	power[0] = 1;
	for (int i = 1; i < N; i++) {
		if (power[i-1] > inf/base) 
			power[i] = inf;
		else
			power[i] = power[i-1]*base;
	}
	cout << memorize(0, 0) << endl;
}
