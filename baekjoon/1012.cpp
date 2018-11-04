#include <iostream>
#include <string.h>
#include <vector>
#include <functional>

#define x first
#define y second 

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("1012.in", "r", stdin);
#endif
	int zone[51][51], visit[51][51];
	int t, m, n, k, x, y;
	cin >> t;

	function<int(int,int)> dfs = [&](int x, int y) {
		if (visit[x][y] || !zone[x][y]) return 0;
		visit[x][y] = 1;
		static vector<pair<int,int>> dt = {{0,1}, {0,-1}, {-1,0}, {1,0}};
		for (auto d : dt) {
			auto nx = x + d.x, ny = y + d.y;
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			dfs(nx, ny);
		}
		return 1;
	};

	while (t--) {
		memset(zone, 0, sizeof(zone));	
		memset(visit, 0, sizeof(visit));	
		cin >> m >> n >> k;
		while (k--) {
			cin >> x >> y;
			zone[x][y] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (dfs(j, i)) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
