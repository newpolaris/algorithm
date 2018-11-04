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
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	vector<int> k(9);
	for (auto& i : k) cin >> i;
	auto num = max_element(all(k));
	cout << *num << endl << (distance(k.begin(), num)+1) << endl;
	return 0;
}
