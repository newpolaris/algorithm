#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	string a;
	cin >> a;
	cout << a.size() << endl;
	return 0;
}
