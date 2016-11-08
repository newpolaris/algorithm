#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 15;
using vi = vector<int>;
bool ispromising(const vi& board, int row, int col) {
	for (int c = 0; c < col; c++) {
		int r = board[c];
		if (row == r) return false;
		if (r - c == row - col) return false;
		if (r - row == col - c) return false;
	}
	return true;
}

int dfs(vector<int>& board, int col) {
	if (col >= board.size()) 
		return 1;
	int sum = 0;
	for (int row = 0; row < board.size(); row++) {
		if (ispromising(board, row, col)) {
			board[col] = row;
			sum += dfs(board, col+1);
		}
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
