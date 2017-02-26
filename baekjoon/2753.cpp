#include <iostream>
#include <vector>

using namespace std;

int visit[101];
vector<vector<int>> adj;

int dfs(int p) {
	if (visit[p]) return 0;
	visit[p] = 1;
	int cnt = 1;
	for (auto a : adj[p]) {
		cnt += dfs(a);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	int n, link, a, b;
	cin >> n >> link;
	adj.resize(n);
	while (link--) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	cout << dfs(0)-1 << endl;

	return 0;
}
