#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

#if _DEBUG
void print2d(vector<vector<int>>& m) {
	for (int r = 0; r < 6; r++) {
		for (int c = 0; c < 6; c++) {
			printf("%3d ", m[r][c]);
		}
		printf("\n");
	}
}
#endif

int main() {
#ifdef _DEBUG
	freopen("mileage.in", "r", stdin);
#endif
	int c, m, p, w, n, t;
	cin >> c;
	while (c--) {
		cin >> m >> p;
		auto v = m + p + 2;
		int source = 0, sink = v - 1;
		vector<vector<int>> capacity(v, vector<int>(v, 0));
		int flow[v][v];
		int mileage[m], price[p];
		for (int i = 0; i < m; i++) cin >> mileage[i];
		for (int i = 0; i < p; i++) cin >> price[i];
		auto max_mileage = accumulate(mileage, mileage+m, 0);
		memset(flow, 0, sizeof(flow));
		for (int i = 0; i < m; i++) {
			cin >> n;
			for (int j = 0; j < n; j++)  {
				cin >> t;
				capacity[1+i][1+m+t] = max_mileage; 
			}
		}
		for (int i = 0; i < m; i++) capacity[0][i+1] = mileage[i];
		for (int i = 0; i < p; i++) capacity[1+m+i][sink] = price[i];;
		int totalFlow = 0;
		while (true) {
			vector<int> parent(v, -1);
			parent[0] = 0;
			queue<int> q;
			q.push(0);
			while (!q.empty() && parent[sink] == -1) {
				auto here = q.front();
				q.pop();
				for (int there = 0; there < v; there++) {
					if (capacity[here][there] - flow[here][there] > 0 
							&& parent[there] == -1) {
						q.push(there);
						parent[there] = here;
					}
				}
			}
			if (parent[sink] == -1) break;
			int amount = max_mileage;
			for (int p = sink; p != source; p = parent[p]) {
				amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
			}
			for (int p = sink; p != source; p = parent[p]) {
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}
			totalFlow += amount;
		}
		cout << totalFlow << endl;
	}
	return 0;
}
