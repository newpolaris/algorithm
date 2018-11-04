#include <iostream>
#include <string>
#include <vector>

#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define fori(i, a, b) for (int i = (a), i##_end_ = (b); i > i##_end_; --i)

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("1100.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	vector<string> board(8);
	for (auto& s : board) cin >> s;
	int cnt = 0;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if ((r+c)%2 == 0 && board[r][c] == 'F')
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
