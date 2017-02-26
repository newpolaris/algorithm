#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	vector<int> score(5);
	for (auto& s : score) cin >> s;
	for_each(all(score), [](int& i) { if (i < 40) i = 40; });
	cout << (accumulate(all(score), 0)/5) << endl;;
	return 0;
}
