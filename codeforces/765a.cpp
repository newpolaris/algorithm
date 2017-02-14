#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("765a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string home, tmp;
	cin >> home;
	getline(cin, tmp);
	forn(i, 0, n) {
		getline(cin, tmp);
		auto a = tmp.substr(0, 3);
		auto b = tmp.substr(5, 3);
	}
	cout << (n % 2 == 0 ? "home" : "contest") << endl;

	return 0;
}
