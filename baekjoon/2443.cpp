#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <regex>
#include <iterator>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = n; i > 0; i--) {
		fori (j, n-i, 0) cout << " ";
		forn (j, 0, 2*i-1) cout << "*";
		cout << endl;
	}
	return 0;
}
