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
	const int inf = -1;
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

	int ip = 0;
	while (ip < pre.size() && pre[ip] >= 0) ip++;
	int is = 0;
	int mp = ip > 0 ? pre[ip-1] : -1;
	while (is >= 0 && suf[is] >= 0 && a.size()-suf[is]-1 > mp) 
		is++;
	auto r = b.substr(0, ip) + b.substr(b.size()-is, is);
	cout << (r.empty() ? "-" : r) << endl;

	return 0;
}
