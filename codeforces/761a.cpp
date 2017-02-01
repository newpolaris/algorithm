#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	cout << ((!(a == b && b == 0) && abs(a-b) <= 1) ? "YES" : "NO") << endl;
}
