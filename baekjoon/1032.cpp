#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<string> arr(n);
	forn(i, 0, n) cin >> arr[i];
	int k = arr[0].size();
	vector<char> s;
	forn(i, 0, k) {
		char c = arr[0][i];
		forn(j, 1, n) {
			if (arr[j][i] != c) { 
				c = '?';
				break;
			}
		}
		s.push_back(c);
	}
	copy(s.begin(), s.end(), ostream_iterator<char>(cout, ""));
	cout << endl;
	
	return 0;
}
