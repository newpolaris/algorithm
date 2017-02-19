#include <iostream>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	int r1, s;
	cin >> r1 >> s;
	cout << (2*s-r1) << endl;
	return 0;
}
