#include <iostream>
#include <string.h>
#include <vector>

int main() {
#ifdef _DEBUG
	freopen("promises.in", "r", stdin);
#endif
	using namespace std;
	int c, v, a, b, d, w, m, n;
	const int MAX_V = 201, inf = 987654321;
	int adj[MAX_V][MAX_V];
	auto update = [&](int a, int b, int d) {
		bool bReleased = false;
		for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++) {
			int mind = min(adj[i][a] + d + adj[b][j], adj[i][b] + d + adj[a][j]);
			if (adj[i][j] > mind) {
				adj[j][i] = adj[i][j] = mind;
				bReleased = true;
			}
		}
		return bReleased;
	};
	cin >> c;
	while (c--) {
		cin >> v >> m >> n;
		for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			adj[i][j] = (i == j) ? 0 : inf;
		while (m--) {
			cin >> a >> b >> d;
			update(a, b, d);
		}
		int cnt = 0;
		while (n--) {
			cin >> a >> b >> d;
			cnt += update(a, b, d) == false;
		}
		cout << cnt << endl;
	}

	return 0;
}
