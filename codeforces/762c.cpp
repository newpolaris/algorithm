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

	// a 범위에 따라갈 pre/suf의 next를 가르키는 pointer
	int pi = 0;
	int si = distance(suf.begin(), max_element(suf.begin(), suf.end()));

	// a 의 범위를 변화시키며 pre/suf 중 각각에 주고 maximum 을 찾는다
	for (int i = 0; i < a.size(); i++) {
		int pre_range = i;
		int suf_range = a.size() - i;
		if (pi < b.size() && pre[pi] < pre_range) 
			pi += 1;
		while (si >= 0 && (suf[si] > suf_range || b.size()-suf[si]-1 < pre[pi])) 
			si -= 1;
		if (maxcnt < si+pi+1) {
			maxcnt = si+pi+1;
			maxidx = {pi, si+1};
		}
	}
	auto r = b.substr(0, maxidx.first) + b.substr(b.size()-maxidx.second, maxidx.second);
	cout << (r.empty() ? "-" : r) << endl;

	return 0;
}
