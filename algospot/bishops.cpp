#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int m, n, bsize;
int mn[2];
const int MAX_N = 100;
int in[MAX_N][MAX_N];
int dx[] = {-1, 1};
int dy[] = {1, 1};
vector<vector<int>> adj;
vector<int> aMatch, bMatch;
vector<bool> visited;
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < n; b++) {
		if (!adj[a][b]) continue;
		if (bMatch[b] == -1 || dfs(bMatch[b])) {
			bMatch[b] = a;
			aMatch[a] = b;
			return true;
		}
	}
	return false;
}
int bipartileMatch() {
	aMatch = vector<int>(m, -1);
	bMatch = vector<int>(n, -1);
	int cnt = 0;
	for (int start = 0; start < m; start++) {
		visited = vector<bool>(m, false);
		if (dfs(start))
			cnt++;
	}
	return cnt;
}
int main() {
#ifdef _DEBUG
	freopen("bishops.in", "r", stdin);
#endif
	int c;
	char ch;
	cin >> c;
	while (c--) {
		cin >> bsize;
		memset(in, 0, sizeof(in));
		for (int r = 0; r < bsize; r++) {
			for (int c = 0; c < bsize; c++) {
				cin >> ch;
				in[r][c] = ch == '*';
			}
		}
		mn[0] = mn[1] = 0;
		vector<vector<vector<int>>> dt
			(2, vector<vector<int>>(bsize, vector<int>(bsize, -1)));
		auto Inside = [&](int x, int y) {
			return 0 <= x && x < bsize && 0 <= y && y < bsize;
		};
		for (int r = 0; r < bsize; r++) {
			for (int c = 0; c < bsize; c++) {
				for (int d = 0; d < 2; d++) {
					if (dt[d][r][c] != -1) continue;
					int x = c, y = r;
					while (Inside(x, y) && in[x][y] == 0) {
						dt[d][y][x] = mn[d];
						x += dx[d], y += dy[d];
					}
					mn[d]++;
				}
			}
		}
		adj = vector<vector<int>>(mn[0], vector<int>(mn[1], 0));
		for (int r = 0; r < bsize; r++) {
			for (int c = 0; c < bsize; c++) {
				int a = dt[0][r][c], b = dt[1][r][c];
				if (a != -1 && b != -1) {
					adj[a][b] = 1;
				}
			}
		}
		m = mn[0], n = mn[1];
		cout << bipartileMatch() << endl;
	}
	return 0;
}
