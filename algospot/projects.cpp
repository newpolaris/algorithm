#include <iostream>
#include <vector>
#include <string.h>
#include <numeric>
#include <queue>
using namespace std;
const int source = 0, sink = 1, inf = 1000000;
vector<vector<int>> capacity, flow;
// Edmonds-karp
int networkFlow() {
	const int node_cnt = capacity.size();
	int totalFlow = 0;	
	while (true) {
		vector<int> parent(node_cnt, -1);
		parent[source] = source;
		queue<int> q;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			auto here = q.front(); q.pop();
			for (int there = 0; there < node_cnt; there++) {
				if (capacity[here][there] - flow[here][there] > 0
				 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if (parent[sink] == -1)
			break;
		int amount = inf;
		for (int p = sink; p != source; p = parent[p])
			amount = min(amount, capacity[parent[p]][p]);
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}
int main() {
#ifdef _DEBUG
	freopen("projects.in", "r", stdin);
#endif
	int c, m, n, k;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<int> profit(n);
		for (auto& i : profit) cin >> i;
		vector<int> cost(m);
		for (auto& i : cost) cin >> i;
		int node_cnt = 2 + n + m;
		capacity = vector<vector<int>>(node_cnt, vector<int>(node_cnt, 0));
		flow = vector<vector<int>>(node_cnt, vector<int>(node_cnt, 0));
		for (int i = 0; i < n; i++) {
			cin >> k; 
			while (k--) {
				int j;
				cin >> j;
				capacity[2+i][2+n+j] = inf;
			}
		}
		for (int i = 0; i < n; i++)
			capacity[source][2+i] = profit[i];
		for (int i = 0; i < m; i++)
			capacity[2+n+i][sink] = cost[i];
		cout << (accumulate(profit.begin(), profit.end(), 0) - networkFlow()) << endl;
	}
	return 0;
}
