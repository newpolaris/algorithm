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
 * 1. 영어 해석이 문제
 * 각 문자은 substring의 길이가 length 초과인 곳에 존재할 수 없음
 */

int n;
string str;
vector<int> alpha(26);
const int MOD = 1000000007;
// 한 부분 substring의 최대 길이
int maxL = 0;
// 1,2 번 용
typedef int Int;
Int cache[1001][1001];
// 3번 용
int cache2[1001][1001];

// 참고로, 모든게 가능 할 때의 갯수는 각 부분을 나누거나, 나누지 않거나 2^(n-1) 개임

// 각 부분 블록이 가능한지 검사한다
int valid(int s, int l) {
	if (l == 0) return 0;
	for (int i = 0; i < l; i++) {
		char c = str[s+i];
		int idx = c - 'a';
		// substring length를 넘어가는 alphabet char 가 있으면 포기
		if (alpha[idx] < l) 
			return 0;
	}
	// 나머지건 어떻게든 1개씩 선택하면 가능한 경우가 존재할 것
	// 그러므로 부분 substring 만 valid 하면 됨
	maxL = max(l, maxL);
	return 1;
}

Int dp(int s, int l) {
	if (l == 0) return 1;
	Int& ret = cache[s][l];
	if (ret >= 0) 
		return ret;
	ret = 0;
	// 1:n-1, 2:n-2 의 갯수를 센다
	for (int i = 1; i <= l; i++) {
		// dp(s, i)를 계산해서 곱하면 중복이 발생하므로,
		// prefix를 고정으로 두고 나머지를 계산
		auto a = valid(s, i);
		if (a == 0) continue;
		// a는 고정된 1개 방식이므로 b 만 더하면 됨. 1*b = b
		auto b = dp(s+i, l-i) % MOD;
		ret += b;
		// 더하고 나머지 하지
		ret %= MOD;
	}
	return ret;
}

int dp2(int s, int l) {
	if (l == 0) 
		return 0;
	int& ret = cache2[s][l];
	if (ret >= 0) 
		return ret;
	ret = 1001;
	for (int i = 1; i <= l; i++) {
		auto a = valid(s, i);
		if (a == 0) continue;
		auto cnt = 1 + dp2(s+i, l-i);
		ret = min(cnt, ret);
	}
	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("766c.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n;
	cin >> str;
	for (auto& a : alpha)
		cin >> a;
	cout << dp(0, n) << endl;
	cout << maxL << endl;
	cout << dp2(0, n) << endl;
	return 0;
}
