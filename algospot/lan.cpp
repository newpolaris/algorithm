#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("lan.in", "r", stdin);
#endif
	using FP = double;
	using pi = pair<int, int>;
	int c, n, m, a, b;
	const int MAX_V = 500, inf = 987654321;
	FP adj[MAX_V][MAX_V];
	pi pos[MAX_V];
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> pos[i].first;
		for (int i = 0; i < n; i++) cin >> pos[i].second;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				auto dx = (pos[i].first - pos[j].first);
				auto dy = (pos[i].second - pos[j].second);
				adj[i][j] = adj[j][i] = dx*dx + dy*dy;
			}
		while (m--) {
			cin >> a >> b;
			adj[a][b] = adj[b][a] = 0.0;
		}
		vector<bool> added(n, false);
		vector<FP> minWeight(n, 1e10);
		minWeight[0] = 0;
		FP dist = 0.0;
		for (int iter = 0; iter < n; iter++) {
			int u = -1;
			for (int i = 0; i < n; i++) {
				if (!added[i] && (u == -1 || minWeight[u] > minWeight[i])) 
					u = i;
			}
			added[u] = true;
			dist += sqrt(minWeight[u]);
			for (int i = 0; i < n; i++) {
				if (!added[i] && adj[u][i] < minWeight[i]) {
					minWeight[i] = adj[u][i];
				}
			}
		}
		cout << fixed << setprecision(9) << dist << endl;
	}
	return 0;
}
