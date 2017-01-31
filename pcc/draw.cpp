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
•1 ≦ ki ≦ 10^8
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
		for (auto& i : k)
			cin >> i;
		sort(ALL(k));
		vector<set<int>> ways(m+1);
		REP(i, 1, m+1) {
			for (auto j : k) {
				if (i - j < 0) break;
				if (i - j == 0) {
					ways[i].insert(1);
				}
				for (auto t : ways[i-j]) {
					if (t >= ndraw) continue;
					ways[i].insert(t+1);
				}
			}
		}
		cout << (ways[m].end() != find(ALL(ways[m]), ndraw) ? "Yes" : "No") << endl;
	}
	return 0;
}
