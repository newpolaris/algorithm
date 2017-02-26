#include <iostream>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	int a, b;
	int n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		cout << (a+b) << endl;
	}
	return 0;
}
