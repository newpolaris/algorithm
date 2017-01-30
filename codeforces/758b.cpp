#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

// EXAMPLE을 보면 알겠지만 4개씩 반복된다. "RYBGRYBGRY", "YBGRYBGRYBG"
// 어떻게 4개 연속으로 봐도 같은게 없다는 제약은 강하다.
int main() {
#ifdef _DEBUG
	freopen("758b.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	const vector<char> blub = {'R', 'B', 'Y', 'G'};
	vector<pair<int, char>> idx;
	for (auto b : blub) 
		idx.push_back({distance(s.begin(), find(ALL(s), b)) % 4, b});
	sort(ALL(idx));
	map<char, int> cnt;
	REP(i, 0, SZ(s)) {
		if (s[i] != '!') continue;
		cnt[idx[(i % 4)].y]++;
	}
	REP(i, 0, 4) {
		cout << cnt[blub[i]] << " \n"[i == 3];
	}
	return 0;
}
