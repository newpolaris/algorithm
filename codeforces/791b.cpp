#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second

using namespace std;

int n, m, a, b;
vector<vector<int>> adj;
vector<bool> visit;

int dfs(int node, int depth) {
	visit[node] = true;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (depth == 2 && !visit[next]) {
			return false;
		}
		if (!visit[next])
			if (!dfs(next, depth+1))
				return false;
	}
	return true;
}

bool check() {
	for (int i = 0; i < n; i++) {
		if (!visit[i])
			if (!dfs(i, 0))
				return false;
	}
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("791b1.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	adj.assign(n, vector<int>());
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visit.assign(n, false);
	cout << (check() ? "YES" : "NO") << endl;
	return 0;
}
