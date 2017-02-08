#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("750a2.in", "r", stdin);
#endif
	int n, k;
	cin >> n >> k;
	auto r = (240 - k);
	int i = 0;
	int timepassed = 0;
	while (true) {
		timepassed += (i+1)*5; 
		if (r < timepassed)
			break;
		i++;
	}
	cout << min(i,n) << endl;

	return 0;
}
