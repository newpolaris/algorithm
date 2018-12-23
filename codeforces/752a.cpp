#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("752a0.in", "r", stdin);
#endif
	int lanes, desks, k;
	cin >> lanes >> desks >> k;
	k--;
	cout << (k/(2*desks) + 1);
	cout << " " << ((k%(2*desks)) / 2 + 1);
	cout << " " << (k % 2 ? "R" : "L") << endl;
	return 0;

}
