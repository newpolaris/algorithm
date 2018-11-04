#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)
#define x first
#define y second 

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	map<char, int> alpha;
	for (auto i = 'a'; i <= 'z'; i++) alpha[i] = 0;
	string word;
	cin >> word;
	for (auto c : word) alpha[c]++;
	for (auto p : alpha) cout << p.y << " ";
	cout << endl;
	return 0;
}
