#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <cstdio>
#include <algorithm>

#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> adj;

int visit[1001];
void dfs(int a) {
	if (visit[a]) 
		return;
	visit[a] = 1;
	cout << a+1 << " ";
	for (auto v : adj[a])
		dfs(v);
}

void bfs(int a) {
	queue<int> node;
	node.push(a);
	while (!node.empty()) {
		int b = node.front();
		node.pop();
		if (visit[b]) continue;
		visit[b] = 1;
		cout << b+1 << " ";
		for (auto v : adj[b]) {
			node.push(v);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("1260.in", "r", stdin);
#endif
	int n, m, v, a, b;
	scanf("%d%d%d", &n, &m, &v);
	adj.resize(n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	for (auto& k : adj)
		sort(all(k));

	memset(visit, 0, sizeof(visit));
	dfs(v-1);
	cout << endl;
	memset(visit, 0, sizeof(visit));
	bfs(v-1);
	cout << endl;

	return 0;
}