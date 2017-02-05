/* 
 * 해석: 연속해서 2개가 같은 user는 안나옴.
 * It means that there could not be two or more messages in a row
 * with the same sender. Moreover, a sender never mention himself 
 * in his messages.
 *
 * 불안한지 한번더 적혀 있군
 *
 * It is guaranteed that in each chat no known sender mention himself 
 * in his messages and there are no two neighboring messages with the
 * same known sender.
 *
 * ?: yes, netman
 * klinchuh: yes, coach!
 *
 * 첫번째는 2번째인 klinchuh 와 나와있는 netman 만 아니면 된다.
 * bananay2001, tigerrrrr 둘다 나와도 됨.
 */
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

vector<string> split(const string& input, const string& reText) {
	regex re(reText);
	// passing -1 as the submatch index parameter performs splitting
	sregex_token_iterator first{ALL(input), re, -1}, last;
	return {first, last};
}

void solve() {
	int n, m; // num of pepople, num of message
	cin >> n;
	vector<string> names(n);
	for (auto& a : names)
		cin >> a;
	cin >> m;

	auto getIdx = [&](string i) {
		int idx = -1;
		auto pos = find(ALL(names), i);
		if (names.end() != pos)
			idx = distance(names.begin(), pos);
		return idx;
	};
	
	// skip newline
	string tmp;
	getline(cin, tmp);

	vector<string> message(m);
	for (auto& a : message)
		getline(cin, a);
	vector<vector<bool>> canUse(m, vector<bool>(n, false));
	vector<string> bodies;
	REP(i, 0, message.size()) {
		auto msg = split(message[i], "[:]");
		auto name = msg[0];
		auto body = msg[1];
		auto idx = getIdx(name);
		bodies.push_back(body);
		if (idx >= 0) {
			canUse[i][idx] = true;
			continue;
		} else {
			canUse[i] = vector<bool>(n, true);
			for (int k = 0; k < n; k++) {
				if (string::npos != body.find(names[k]))
					canUse[i][k] = false;
			}
		}
	}

	vector<vector<int>> cache(m, vector<int>(n, -1));
	// 첫번째 시작열 구성, 다음 열과 겹치는 것과 검사하진 않고 가능한 것 표시
	REP(i, 0, n)
		if (canUse[0][i])
			cache[0][i] = 0; // -1 이 아닌 값. 의미는 없다
	REP(i, 0, m-1) {
		/*
		 * 모든 가능한 경우를 찾아서 다음 단계로 넘긴다.
		 * 뒤에 것과 같은게 아니여야 함.
		 */
		REP(a, 0, n) {
			if (cache[i][a] == -1) continue;
			REP(b, 0, n) {
				if (a == b) continue;
				// b 가 사용가능한 사람이면, 출력을 위해 a를 기록
				if (canUse[i+1][b])
					cache[i+1][b] = a;
			}
		}
	}

	// buble sort 처럼 전달되므로, 마지막 열에 기록된게 없다면 방법이 없는 것
	auto pos = find_if(ALL(cache[m-1]), [](int i) { return i != -1; });
	if (pos == cache[m-1].end()) {
		cout << "Impossible" << endl;
	} else {
		auto idx = distance(cache[m-1].begin(), pos);
		vector<string> nameout;
		for (int msgIdx = m - 1; msgIdx >= 0; msgIdx--) {
			nameout.push_back(names[idx]);
			idx = cache[msgIdx][idx];
		}
		reverse(ALL(nameout));
		REP(i, 0, m) {
			cout << nameout[i] << ":" << bodies[i] << endl;
		}

	}
}

int main() {
#ifdef _DEBUG
	freopen("754c.in", "r", stdin);
#endif
	int t; // number of tests
	cin >> t; 

	while (t--) {
		solve();
	}
}
