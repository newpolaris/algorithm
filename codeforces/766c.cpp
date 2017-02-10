#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <queue>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

/*
 * 영어 해석이 문제
 * 각 문자은 substring의 길이가 length 초과인 곳에 존재할 수 없음
 * 참고로, 모든게 가능 할 때의 갯수는 각 부분을 나누거나, 
 * 나누지 않거나 2^(n-1) 개임
 * reculsive 풀이방법.
 * 중복 제거를 위해,
 * |--->[posible]|
 *
 * aab 의 예를 들면,
 *
 * |a->[ab]
 * |aa->[b]
 * |aab->[]
 *
 * 화살표를 고정시켜 증가시켜서 계산, 결국 왼쪽은 valid 만 따진다.
 * 꺼꾸로 해도 될듯
 
int dp(int s) {
	// 기본 1개 a는 통과했으므로
	if (s >= n) return 1;
	int& ret = cache[s];
	if (ret >= 0) 
		return ret;
	ret = 0;
	// 1:n-1, 2:n-2 의 갯수를 센다
	for (int i = 1; i <= n - s; i++) {
		// dp(s, i)를 계산해서 곱하면 중복이 발생하므로,
		// prefix를 고정으로 두고 나머지를 계산
		auto a = valid(s, i);
		if (a == 0) continue;
		// a는 고정된 1개 방식이므로 b 만 더하면 됨. 1*b = b
		auto b = dp(s+i);
		// 더하고 나머지 하지
		ret = (ret + b) % MOD;
	}
	return ret;
}
*/

int main() {
#ifdef _DEBUG
	freopen("766c0.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n;
	string str;
	vector<int> alpha(26);
	const int MOD = 1000000007;
	// 한 부분 substring의 최대 길이
	int maxL = 0;
	// 1,2번 용
	int dp[1001];
	// 3번 용
	int dp2[1001];

	cin >> n;
	cin >> str;
	for (auto& a : alpha)
		cin >> a;
	/*
	 * 1칸 부터 n칸까지 채운다
	 * dp(k)를 k칸 채웠을 때의 갯수라 하자
	 * 이전 dp(0)...dp(k-1) 이 계산되어 있다고 할때,
	 * dp(k)는,
	 *
	 * 새로 추가된 칸으로 생성가능한 크기를 모두 테스트,
	 * 즉, 위의 reculsive의 반대방향이라 보면된다.
	 *
	 * [aa]<-b : 오른쪽 1칸
	 * [a]<-ab : 오른쪽 2칸
	 * []<-aab : 오른쪽 3칸
	 *
	 * 오른쪽 크기, k-i, for i = k-1 to 0
	 * [aa]:b = dp(2) 1칸
	 * [a]:ab = dp(1) 2칸
	 * []:aab = dp(0) 3칸
	 *
	 * 중복 계산을 막기위해 오른쪽은 고정
	 *
	 * b, ab, aab 로 왼쪽으로 늘려가며 가능한 limit 값의 한계의 최소치를 기록해 두어야
	 *
	 * f = min(f, arr[s[x]])
	 * if (k-i > f) continue
	 */
	maxL = 0;
	dp[0] = 1;
	// dp2는 카운트를 최소화 취할 것이므로 n 으로 채움
	REP(i, 0, n+1) 
		dp2[i] = n;
	dp2[0] = 0;
	// dp, dp2를 각 크기일때의 가능 횟수, 최소 sub div로 하고 n 까지 구한다
	for (int k = 1; k <= n; k++) {
		int f = k;
		for (int i = k-1; i >= 0; i--) {
			/* 각 k 에 대해 역으로 1칸에서부터 k까지 늘려가는데,
			 * 각 칸의 크기 허가치의 최소를 누적 보관
			 */
			f = min(f, alpha[str[i]-'a']);
			// 현재 늘려간 칸의 크기
			auto fixedlen = k-i;
			// 최소 크기 허용치 넘으면 퇴출
			if (fixedlen > f) continue;
			maxL = max(maxL, fixedlen);
			// 칸을 고정했을 때,
			//  왼쪽의 가능한 모든 경우 누적
			dp[k] = (dp[k] + dp[i]) % MOD;
			//  현재 칸이 나눠지면 숫자가 1개 더해져야 겠지
			dp2[k] = min(dp2[i]+1, dp2[k]);
		}
	}
	cout << dp[n] << endl << maxL << endl << dp2[n] << endl;

	return 0;
}
