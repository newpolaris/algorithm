#include <iostream>
#include <limits>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

#define mp make_pair
#define rep(i,a) for (int i = 0; i < (int)a; ++i)
#define rep2(i,a,b) for (int i = a; i < (int)b; ++i)
using namespace std;
typedef vector<int> vi;
const int INF = 987654321;
const int MOD = 1000000007;

vector<string> board;
const int dy[4] = { -1, 0, 0, 1 };
const int dx[4] = { 0, 1, -1, 0 };
void dfs(int y, int x) {
	if (y == 0 || y == board.size() - 1 || x == 0 || x == board[0].size() - 1) return;
	if (board[y][x] != 'B' && board[y][x] != '.')
		return;
	board[y][x] = '&';
	rep(i, 4) {
		const int ny = y + dy[i];
		const int nx = x + dx[i];
		dfs(ny, nx);
	}
}
void setChk(int y, int x) {

	dfs(y, x);
}

int main() {
	freopen("D.in", "r", stdin);

	double nn, mm, kk;
	scanf("%lf%lf%lf", &nn, &mm, &kk);
	board.resize(mm * 2 + 1);
	char buf[300];
	rep(i, board.size()) {
		scanf("%s",buf);
		string s(buf);
		board[i] = buf;
	}
	reverse(board.begin(), board.end());

	int n = nn * 2; 
	int m = mm * 2;
	int k = kk * 2;
	int hy = 0, hx = k;	//k 는 0보다 크다
	int ny, nx, dir = -1;
	int cnt = 0;
	for (int y = 0; y <= m; ++y) {
		hy++;
		hx = hx + dir;
		if (board[hy - 1][hx] == 'B' || board[hy - 1][hx] == '.') {
			++cnt;
			setChk(hy - 1, hx);
		}
		if (board[hy][hx - dir] == 'B' || board[hy][hx - dir] == '.') {
			++cnt;
			setChk(hy, hx - dir);
		}
		if (board[hy][hx] == 'B' || board[hy][hx] == '.') {
			++cnt;
			setChk(hy, hx);

		}
		if (hx == 0) dir = 1;
		if (hx == n) dir = -1;
		if (hy == m) break;
	}
	for (int y = m; y >= 0; --y) {
		hy--;
		hx = hx + dir;
		if (board[hy + 1][hx] == 'B' || board[hy + 1][hx] == '.') {
			++cnt;
			setChk(hy + 1, hx);
		}
		if (board[hy][hx - dir] == 'B' || board[hy][hx - dir] == '.') {
			++cnt;
			setChk(hy, hx - dir);
		}
		if (board[hy][hx] == 'B' || board[hy][hx] == '.') {
			++cnt;
			setChk(hy, hx);
		}
		if (hx == 0) dir = 1;
		if (hx == n) dir = -1;
		if (hy == 0) break;
	}
	printf("%d", cnt);
	return 0;
}

