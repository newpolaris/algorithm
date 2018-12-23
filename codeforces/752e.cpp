#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

typedef long long LL;

using namespace std;

const int radix_len = 1e7+5;
LL cnt[radix_len];

int main() {
#ifdef _DEBUG
	freopen("752e.in", "r", stdin);
#endif
	int n, k, a;
	ios_base::sync_with_stdio(false);
	cin >> n >> k; 

	LL tot = 0;
	// vector<int> cnt(radix_len, 0);
	// main 안에서는 segment fault 발생. 외부에는 문제 없음

	REP(i, 0, n) {
		cin >> a;
		cnt[a]++;
		tot += a;
	}
	if (tot < k) {
		cout << -1 << endl;
		return 0;
	}

	/*
	 * 최갑부에게 쉽다고 듣고 풀려고 했을 때 2가지 문제가 존재했음
	 * binary search를 귤의 최소 숫자라 할 때 쪼개버리면 복구는 어케하지?
	 * 그냥 size를 k 맞추거라면, 나누고 넣으면서 k개를 어떻게 맞출까?
	 *
	 * Editorial: 
	 * 하나씩 나눠서 가장 좋은 정답을 찾자.
	 * 가장 큰 것을 나누면서 현재 정답(k번째 큰 수)을 수정해 나가자.
	 * 2개 경우.
	 * 1) 나눈 것 모두 현재 정답 보다 클 경우,
	 * 맨 첫 원소를 삭제하고 k 번째 정답 갱신하여 사이즈를 k를 유지하자
	 * 2) 나눈 것 하나는 현재 정답 보다 작은 경우, 스톱
	 *
	 * 여기서 O(n)으로 풀려면? two pointer 
	 * To emulate this process in a fast way, we can keep an array from 1 to A,
	 * where A = 10^7 is the maximum possible number of slices in a part, where
	 * each cell contain the current number of parts of that size.
	 * Thus, we can maintain two pointers: one to the current answer and one to the
	 * current maximum size, so the whole process can be done in O(n). 
	 * The overall complexity is O(n + A).
	 *
	 * Radix sort랑 비슷한 느낌인데, 다음걸로 넘어가는걸 어떻게 구현?
	 */
	auto bound = 1;
	auto sum = 0LL;
	for (int i = radix_len - 1; i > 0; i--) {
		sum += cnt[i];
		if (sum >= k) {
			bound = i;
			break;
		}
	}
	for (int i = radix_len - 1; i > 1; i--) {
		if (i/2 < bound) 
			break;

		// 한개씩 하지 말고 block 단위로, k 범위를 직접 tracking 하지 말고 아래 방법 이용.
		cnt[i/2] += cnt[i];
		cnt[i - i/2] += cnt[i];
		sum += cnt[i];
		cnt[i] = 0;

		// sum은 cnt[base]를 포함한 영역. cnt[base] 보다 커졌을 경우 다음단계로.
		// 이러면, base에서 몇번째인지 안 새어도 된다.
		while (sum - cnt[bound] >= k) {
			sum -= cnt[bound];
			bound++;
		}
	}
	cout << bound << endl;
}
