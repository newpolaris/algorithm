/*
 제비 뽑기
 어느 날 친구가 봉지를 들고 와 당신에게 게임을 제안했습니다. 봉지에는 숫자가 쓰여 있는 n장의 종
 이가 들어 있습니다. 당신은 봉지에서 종이를 한 장 뽑고, 숫자를 확인한 후 다시 봉지에 넣는 동작을
 4번 반복하여, 그 숫자의 합이 m이면 당신의 승리, 그렇지 않으면 친구가 승리하게 됩니다. 당신은 이
 게임을 몇 번이나 해 보았지만 한번도 이기지 못했습니다. 화가 난 당신은 봉지를 찢어 모든 종이를 꺼
 낸 후 정말 이길 수 없었는지 조사를 했습니다. 종이에 쓰여 있는 숫자가 K1, K2 ..., Kn일 경우, 합이 m
 이 되는 경우가 있는 지를 조사하고, 방법이 있다면 Yes, 없다면 No를 출력하는 프로그래밍을 작성하
 세요.
 
  제약
 •1 ≦ n ≦ 50
 •1 ≦ m ≦ 10^8
 •1 ≦ k_i ≦ 10^8
 예1) 
 입력 n = 3, m = 10, k = {1, 3, 5}
 출력 Yes
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

// alogirhtm: m - k3 - k4 = k1 + k2
int main() {
#ifdef _DEBUG
	freopen("draw.in", "r", stdin);
#endif
	const int ndraw = 4;

	int c, n, m;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<int> k(n);
		for(auto & i : k) cin >> i;
		set<int> sum2set;
		for (int i = 0; i < k.size(); i++) {
			for (int j = 0; j <= i; j++) {
				sum2set.insert(k[i] + k[j]);
			}
		}

		vector<int> sum2(ALL(sum2set));
		auto bs = [&](int t) {
			int lo = 0;
			int hi = SZ(sum2) - 1;
			while (lo <= hi) {
				auto mid = lo + (hi - lo)/2;
				if (sum2[mid] == t)
					return true;
				else if (sum2[mid] < t)
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			return false;
		};
		bool bFound = false;
		REP(i, 0, SZ(sum2)) {
			bFound = bs(m - sum2[i]);
			if (bFound) break;
		}
		cout << (bFound ? "Yes" : "No") << endl;
	}

	return 0;
}
