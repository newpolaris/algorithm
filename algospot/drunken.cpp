#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 501;
const int INF = 987654321;
using pi=pair<int, int>;
int delay[MAX_V];
pi adj[MAX_V][MAX_V];
int main() {
#ifdef _DEBUG
	freopen("drunken.in", "r", stdin);
#endif
	int v, e, a, b, c, t;
	cin >> v >> e;
	for (int i = 0; i < v; i++)
		cin >> delay[i];
	for (int i = 0; i < v; i++) 
		for (int j = 0; j < v; j++) 
			adj[i][j] = make_pair(i == j ? 0 : INF, 0);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[b-1][a-1].first = adj[a-1][b-1].first = c;
	}
	auto cost = [](pi a) { return a.first+a.second; };
	auto min = [&](int i, int j, int k) {
		auto ab = adj[i][j];
		auto akb = make_pair(adj[i][k].first + adj[k][j].first, 
			max(delay[k], max(adj[i][k].second, adj[k][j].second)));
		if (cost(ab) > cost(akb)
		 || (cost(ab) == cost(akb) && akb.second >= ab.second))
			return akb;
		return ab;
	};
	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				adj[i][j] = min(i, j, k);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (adj[a-1][b-1].first+adj[a-1][b-1].second) << endl;

	}
	return 0;
}
