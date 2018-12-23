#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

/*
 * The trickiest part is the central block. Clearly, only the palindromic 
 * strings may be at the central block. However, there may be many of them,
 * and we should select the one which gives the maximum value overall.
 * There are several cases. Consider the point when you've taken the last pair 
 * from the list of S-s and stopped.
 * If the value of the next element is nonnegative (say, x), we may simply take it
 * and say that x is our possible score for S being in the center. We wouldn't
 * make a valuable pair of it anyway. Otherwise we need to split the last taken
 * pair. Denote the values of last taken strings as a and b (a ≥ b).
 * Note that b < 0, because otherwise it makes no sense to use a separately.
 * If we take a pair, we get score a + b. If we take just the first element,
 * we get score a. So, in this case our possible score is  - b (while a + b is 
 * already added to the main answer!)
 * Now, the central string will be the one with the maximum possible score,
 * and its value should be added to the answer.
 *
 * 위의 구문을 해석을 제대로 못한 것도 있고, 우선 나의 접근법은,
 * 좌우 대칭인 경우, 2개씩 남은 것과 1개씩 남은 것 조합 중 최고 합을 구하기 위해
 * 2개, 1개 남겨서 위에서 부터 2개짝과 1개 짝을 비교해서 최고를 선택하고 나머진
 * 더한다는 이상한 방법이었다.
 *
 * 그 대신, 문제가 된 부분을 풀어 쓰면,
 * 2개 짜리 (a, b), 한개 짜리 (c)
 * r = max(-b, c)
 * 최종 결과는 sum += r
 * 왜냐면, 이미 더한 것 중 음수의 마이너스는 해당 2개 합을 하나로 만드는 것이고
 * 한개 남은 것 중 가운데는 결국 하나만 존재해야 하므로
 */

int idx = 0;
map<string, int> idxTable;
int getIdx(const string& s) {
	if (idxTable.count(s) == 0) {
		idxTable[s] = idx++;
	}
	return idxTable[s];
}

int main() {
#ifdef _DEBUG
	freopen("752d.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);

	int k, n, a;
	string str;
	cin >> k >> n;
	vector<bool> bPalindrome(k);
	vector<vector<int>> l(k), r(k);
	forn(i, 0, k) {
		cin >> str >> a;
		auto rev = str;
		reverse(ALL(rev));
		if (str <= rev) {
			if (str == rev)
				bPalindrome[i] = true;
			auto i = getIdx(str);
			l[i].push_back(a);
		} else {
			auto i = getIdx(rev);
			r[i].push_back(a);
		}
	}

	int sum = 0, mid = 0;
	forn(i, 0, k) {
		if (l[i].size() <= 0) 
			continue;
		auto &L = l[i], &R = r[i];
		sort(ALL(L), greater<int>());
		sort(ALL(R), greater<int>());
		if (bPalindrome[i]) {
			auto l_len = L.size();
			for (int t = 0; t < l_len; t += 2) {
				// 홀수개로 끝나는 경우 check
				if (t+1 == l_len) {
					mid = max(mid, L[t]);
				} else {
					// 합의 경우 뒤에 수가 음수일 경우, 앞에거 하나만 남기는
					// 경우를 계산하기 위해 역수를 취한다
					auto a = L[t], b = L[t+1];
					if (a + b > 0) {
						sum += a + b;
						mid = max(mid, -b);
					// 음수일 경우 더하는 경우는 없어야 하며, 앞에거 하나만
					// 남기는 경우를 고려한다. 0 일경우 a == -b 이므로 같다
					} else {
						mid = max(mid, a);
					}
				}
			}
		} else {
			forn(j, 0, min(L.size(), R.size())) {
				int s = L[j]+R[j];
				if (s <= 0) break;
				sum += s;
			}
		}
	}
	cout << (sum+mid) << endl;

	return 0;
}
