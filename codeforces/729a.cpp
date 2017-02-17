#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <string.h>
#include <regex>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define SZ(x) (int((x).size()))

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("729a1.in", "r", stdin);
#endif
	int n;
	cin >> n;
	string wd;
	cin >> wd;
	forn(k, 0, n) {
		int l = wd.size();
		forn(i, 0, l-2) {
			if (wd.substr(i, 3) == "ogo") {
				forn(j, 0, 3) 
					wd[j+i] = '*';
				break;
			}
		}
		forn(t, 0, n) {
			l = wd.size();
			forn(i, 0, l-2) {
				if (wd.substr(i, 3) == "*go") {
					wd = wd.substr(0, i+1) + wd.substr(i+3);
					break;
				}
			}
		}
	}
	cout << wd << endl;
	return 0;
}
