#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 15;
bool can(const vector<int>& board, int row, int col) {
	for (int c = 0; c < col; c++) {
		int r = board[c];
		if (row == r) return false;
		if (r - c == row - col) return false;
		if (r - row == col - c) return false;
	}
	return true;
}

vector<int> possible(const vector<int>& board, int col) {
	vector<int> candi;
	for (int row = 0; row < board.size(); row++) {
		if (can(board, row, col))
			candi.push_back(row);
	}
	return candi;
}

int dfs(vector<int>& board, int col) {
	if (col >= board.size()) 
		return 1;
	auto candi = possible(board, col);
	int sum = 0;
	for (auto& r : candi) {
		board[col] = r;
		sum += dfs(board, col+1);
	}
	return sum;
}

int main() {
#ifdef _DEBUG
	freopen("nqueens.in", "r", stdin);
#endif
	int C, N;
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> board(N, 0);
		cout << dfs(board, 0) << endl;
	}
	return 0;
}
