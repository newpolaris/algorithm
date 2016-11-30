#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int source = 0, sink = 1, m_max = 100, n_max = 12, max_node = 1 + 1 + m_max + n_max;
int n, m, possibleWin, totalFlow;
int capacity[max_node][max_node], flow[max_node][max_node], wins[m_max];
pair<int, int> match[m_max];

int networkFlow(int w) {
	if (possibleWin < w - wins[0]) 
		return -1;
	if (*max_element(wins+1, wins+n) >= w) 
		return -1;
	for (int i = 0; i < n; i++) {
		int maxWin = (i == 0 ? w : w -1);
		capacity[2+m+i][sink] = maxWin - wins[i]; 
	}
	while (true) {
		vector<int> parent(max_node, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while (!q.empty() && parent[sink] == -1) {
			int here = q.front(); q.pop();
			for (int there = 0; there < max_node; there++) {
				if (capacity[here][there] - flow[here][there] > 0 
				 && parent[there] == -1) {
					q.push(there);
					parent[there] = here;
				}

			}
		}
		if (parent[sink] == -1) break;
		int amount = m;
		for (int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = sink; p != source; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}
int findMinMatch() {
	totalFlow = 0;
	for (int i = 0; i <= m; i++) {
		int k = networkFlow(i+wins[0]);
		if (k == m) return i+wins[0];
	}
	return -1;
}
int main() {
#ifdef _DEBUG
	freopen("matchfix.in", "r", stdin);
#endif
	int c;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> wins[i];
		possibleWin = 0;
		for (int i = 0; i < m; i++) {
			cin >> match[i].first >> match[i].second;
			if (match[i].first == 0 || match[i].second == 0)
				possibleWin++;
		}
		memset(capacity, 0, sizeof(capacity));
		for (int i = 0; i < m; i++)
			capacity[source][2+i] = 1;
		for (int i = 0; i < m; i++) {
			auto a = match[i].first, b = match[i].second;
			capacity[2+i][2+m+a] = 1;
			capacity[2+i][2+m+b] = 1;
		}
		memset(flow, 0, sizeof(flow));
		cout << findMinMatch() << endl;
	}
}
