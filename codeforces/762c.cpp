#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("762c1.in", "r", stdin);
#endif
	string a, b;
	cin >> a >> b;
	const int inf = a.size() + 5;
	// For every prefix of B, count how big of a prefix of A you will require. 
	// Call these values p[i]. Put infinity in the cells where even whole A is not enough.
	vector<int> pre(b.size(), inf), suf(b.size(), inf);

	/*
	 * b는 무조건 포함되어야 하므로, 남겨질 b의 최대 매칭을 찾는 문제임
	 * 단순히 양방향 matching 구해서 계산하려면 겹치는 문제 발생하므로,
	 * a에서 필요한 범위를 대신 구한다.
	 */
	for (int i = 0; i < b.size(); i++) {
		int a_idx = i == 0 ? 0 : pre[i-1]+1;
	 	// a_idx를 늘려가면서 최대 필요한 수를 pre에 기록함
		while (a_idx < a.size()) {
			if (a[a_idx] == b[i])
				break;
			a_idx++;
		}
		if (a_idx >= a.size()) 
			break;
		pre[i] = a_idx;
	}

	for (int i = 0; i < b.size(); i++) {
		int a_ridx = i == 0 ? 0 : suf[i-1]+1;
		while (a_ridx < a.size()) {
			if (a[a.size()-a_ridx-1] == b[b.size()-i-1])
				break;
			a_ridx++;
		}
		if (a_ridx >= a.size()) 
			break;
		suf[i] = a_ridx;
	}

	// max matching count, index
	int maxcnt = -1; 
	pair<int, int> maxidx;
	/*
	 * Now try increasing the length of prefix of B, 
	 * while decreasing the length of the suffix until p[pref_len] + s[suf_len]
	 * is less or equal to the length of A.
	 *
	 * 그럼 이제 pre/suf 있는데 n^2가 필요한 건가?
	 *
	 * a는 고정임. a를 0:alen, 1:alen-1, ... alen:0 으로 변경시켜서
	 * 각각을 pre/suf에 주고 matching 된 것의 최대 값을 구하면 됨
	*/
	int a_len = a.size();
	auto pit = pre.begin();
	auto sit = suf.rbegin();

	for (int i = 0; i <= a_len; i++) {
		auto pre_limit = i;
		auto suf_limit = a_len - i;
		while (pit != pre.end() && *pit < pre_limit) 
			pit++;
		auto pcnt = distance(pre.begin(), pit);
		// sit은 꺼꾸로 되어 있으므로 마지막이 전체 다 썻을 경우임
		while (sit != suf.rend() && *sit >= suf_limit)
			sit++;
		auto scnt = suf.size() - distance(suf.rbegin(), sit);
		int cnt = pcnt+scnt;
		if (cnt > maxcnt) {
			maxcnt = cnt;
			maxidx = {pcnt, scnt};
		}
	}
	auto suf_st = max(maxidx.first, (int)b.size()-maxidx.second);
	auto r = b.substr(0, maxidx.first) + b.substr(suf_st, maxidx.second);
	cout << (r.empty() ? "-" : r) << endl;

	return 0;
}

// 다른사람 소스
int main2() {
#ifdef _DEBUG
	freopen("762c.in", "r", stdin);
#endif
	string a, b;
	cin >> a >> b;

	int n = a.size();
	int m = b.size();
	vector<int> pre(n+1), suf(n+1);
	pre[0] = 0;
	/*
	 * 관점을 바꿔 빨리 개산하는 방법은?
	 * a의 pre/suf 를 계산
	 */
	REP(i, 0, n) {
		pre[i+1] = pre[i];
		if (pre[i] < m && a[i] == b[pre[i]]) pre[i+1]++;
	}
	suf[n] = 0;
	for (int i = n-1; i >= 0; i--) {
		suf[i] = suf[i+1];
		if (suf[i] < m && a[i] == b[m-1-suf[i]]) suf[i]++; 
	}

	int maxcnt = -1, maxidx = -1;
	REP(i, 0, n+1) {
		if (chkmax(maxcnt, pre[i]+suf[i])) {
			maxidx = i;
		}
	}

	if (!maxcnt) puts("-"); 
	else {
		REP(i, 0, pre[maxidx]) putchar(b[i]);
		REP(i, max(pre[maxidx], m-suf[maxidx]), m) putchar(b[i]);
	}

	return 0;
}
