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
	int n, s;	
	cin >> n;
	vector<int> multi(n);
	for (auto& i : multi) cin >> i;
	s = accumulate(multi.begin(), multi.end(), 0);
	// 처음 한칸을 제외하고 n-1 칸은 다른 탭이 곱히는 칸이다
	s -= n-1;
	cout << s << endl;

	return 0;
}
