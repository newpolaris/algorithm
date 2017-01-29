#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

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

int main() {
#ifdef _DEBUG
	freopen("762c.in", "r", stdin);
#endif
	string a, b;
	cin >> a >> b;

	int n = a.size();
	int m = b.size();
	vector<int> pre(n+1), suf(n+1);
	pre[0] = 0;
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
