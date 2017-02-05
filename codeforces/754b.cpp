#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#define x first
#define y second 

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define ALL(x) (x).begin(), (x).end()

using namespace std;

vector<string> board;
vector<pair<int,int>> dir = {{1,1}, {1,0}, {0,1}, {1,-1}, {-1,-1}, {-1,0}, {0,-1}, {-1,+1}};
int dfs(int i, int j, int k) {
	if (i < 0 || i > 3 || j < 0 || j > 3) return 0;
	if (board[i][j] == 'x')
		return dfs(i+dir[k].x, j+dir[k].y, k) + 1;
	else 
		return 0;
}

bool search(int i, int j) {
	REP(k, 0, 4) {
		if (dfs(i, j, k) + dfs(i, j, 4+k) - 1 >= 3)
			return true;
	}
	return false;
}

bool find() {
	REP(i, 0, 4) {
		REP(j, 0, 4) {
			if (board[i][j] == 'x') {
				if (search(i, j)) return true;
			} else if (board[i][j] == '.') {
				auto c = 'x';
				swap(board[i][j], c);
				if (search(i, j)) return true;
				swap(board[i][j], c);
			}
		}
	}
	return false;
}

int main() {
#ifdef _DEBUG
	freopen("754b2.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
	board.resize(4);
	for (auto& b : board)
		cin >> b;
	cout << (find() ? "YES" : "NO") << endl;
}
