#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	int min = a*60 + b + c;
	min %= (60*24);
	cout << (min / 60) << " " << (min % 60) << endl;
	return 0;
}
