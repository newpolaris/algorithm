#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <queue>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

string a, b;

int main() {
#ifdef _DEBUG
	freopen("750c0.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	if (a.size() < b.size())
		swap(a, b);
	if (a.size() > b.size())
		cout << a.size() << endl;
	else {
		if (a == b)
			cout << -1 << endl;
		else
			cout << a.size() << endl;
	}

	return 0;
}
