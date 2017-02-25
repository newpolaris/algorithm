#include <iostream>
#include <algorithm>
#include <string>
#include <set>

#define all(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define sz(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("776a0.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);

	string a, b;
	set<string> names;
	cin >> a >> b;
	int n;
	cin >> n;
	cout << a << " " << b << endl;
	names.insert(a);
	names.insert(b);
	while (n--) {
		cin >> a >> b;
		names.erase(names.find(a));
		names.insert(b);
		for (auto a : names)
			cout << a << " ";
		cout << endl;
	}

	return 0;
}
