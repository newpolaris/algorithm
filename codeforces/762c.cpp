#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("762c.in", "r", stdin);
#endif
	string a, b;
	cin >> a >> b;
	const int inf = a.size() + 5;
	vector<int> pre(b.size(), inf), suf(b.size(), inf);
	for (int i = 0; i < b.size(); i++) {
		int c = i == 0 ? 0 : pre[i-1]+1;
		while (c < a.size()) {
			if (a[c] == b[i])
				break;
			c++;
		}
		if (c >= a.size()) 
			break;
		pre[i] = c;
	}

	for (int i = 0; i < b.size(); i++) {
		int c = i == 0 ? 0 : suf[i-1]+1;
		while (c < a.size()) {
			if (a[a.size()-c-1] == b[b.size()-i-1])
				break;
			c++;
		}
		if (c >= a.size()) 
			break;
		suf[i] = c;
	}

	// max matching count, index
	int maxcnt = -1; 
	pair<int, int> maxidx;

	int la = a.size();
	auto pit = pre.begin();
	auto sit = suf.rbegin();

	// a에서 잘려질 범위를 변형시켜 pre/suf 중 각각에 주고 maximum 을 찾는다
	for (int i = 0; i <= la; i++) {
		auto pre_limit = i;
		auto suf_limit = la - i;
		while (pit != pre.end() && *pit < pre_limit) pit++;
		auto pcnt = distance(pre.begin(), pit);
		while ((sit+1) != suf.rend() && *(sit+1) >= suf_limit) { 
			sit++;
		}
		auto scnt = suf.size() - distance(suf.rbegin(), sit) - 1;
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
