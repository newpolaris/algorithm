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
	string str = to_string(a*b*c);
	forn(i, 0, 10) 
		cout << count(str.begin(), str.end(), '0'+i) << endl;
	return 0;
}
