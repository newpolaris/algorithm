#include <iostream>
#include <vector>
#include <map>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("760a.in", "r", stdin);
#endif
	int m, d;
    ios_base::sync_with_stdio(false);
	cin >> m >> d;
	vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	m--; d--;
	auto r = days[m] - (7 - d);
	cout << (1 + r/7 + (r%7 ? 1 : 0)) << endl;
}
