#include <iostream>
#include <vector>

using namespace std;

const int MAX_M = 80, inf = 100000, ADJ_L = MAX_M*MAX_M/2;
int m, n, cm, cn, r, c;
int id[MAX_M][MAX_M];
int adj[ADJ_L][ADJ_L];
int dx[] = { 0, 0, 1, -1};
int dy[] = {-1, 1, 0,  0};
vector<bool> visited;
vector<int> aMatch, bMatch;

bool inRange(int x, int y) {
	if (0 <= x && x < n && 0 <= y && y < m) 
		return true;
	return false;
}

bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < cn; b++) {
		if (adj[a][b]) {
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartileMatch() {
	aMatch = vector<int>(cm, -1);
	bMatch = vector<int>(cn, -1);
	int cnt = 0;
	for (int i = 0; i < cm; i++) {
		visited = vector<bool>(cm, false);
		if (dfs(i))
			cnt++;
	}
	cout << cnt << endl;
	return cnt;
}

int main() {
#ifdef _DEBUG
	freopen("dominos.in", "r", stdin);
#endif
	int c;
	char ch;
	cin >> c;
	while (c--) {
		cm = cn = 0;
		cin >> m >> n;
		memset(adj, 0, sizeof(adj));
		memset(id, -1, sizeof(id));
		for (int r = 0; r < m; r++) {
		for (int c = 0; c < n; c++) {
			cin >> ch;
			if (ch == '#') continue;
			if ((r+c) % 2 == 0)
				id[r][c] = cm++;
			else
				id[r][c] = cn++;
		}
		}
		for (int r = 0; r < m; r++) { 
		for (int c = 0; c < n; c++) {
			if ((r+c) % 2 == 1 || id[r][c] == -1)
				continue;
			for (int i = 0; i < 4; i++) {
				int x = c + dx[i], y = r + dy[i];
				if (inRange(x, y) && id[y][x] != -1)
					adj[id[r][c]][id[y][x]] = 1;
			}
		}
		}
		cout << ((bipartileMatch()*2 == cn+cm) 
				? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}

	return 0;
}
