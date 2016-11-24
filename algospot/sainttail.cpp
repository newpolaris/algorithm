#include <iostream>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("sainttail.in", "r", stdin);
#endif
	int c, e, v, a, b;
	cin >> c;
	while (c--) {
		cin >> e >> v;	
#ifdef _DEBUG
		const int inf = 100;
#else
		const int inf = 987654321;
#endif
		auto nv = v*2;
		int capacity[nv][nv], flow[nv][nv];
		memset(capacity, 0, sizeof(capacity));
		auto print2d = [&]() {
			for (int i = 0; i < nv; i++)  {
				for (int j = 0; j < nv; j++)  {
					printf("%3d ", capacity[i][j]);
				}
				printf("\n");
			}
		};
		int source = 0, sink = nv-1;
		auto in = [](int i) { return i*2; };
		auto out = [](int i) { return i*2+1; };
		memset(flow, 0, sizeof(flow));
		vector<pair<int, int>> link(e);
		for (auto& p : link) cin >> p.first >> p.second;
		vector<int> weight(v-2);
		for (auto& w : weight) cin >> w;
		// 시작 끝 노드에 가상선 추가
		weight.insert(weight.begin(), inf);
		weight.push_back(inf);
		// weight 와 link 에 따라 node 간 연결 추가
		for (auto& l : link) {
			auto a = l.first, b = l.second;
			capacity[out(a)][in(b)] = inf;
			capacity[out(b)][in(a)] = inf;
		}
		// node 의 in/out 간 weight 연결 추가
		for (int i = 0; i < weight.size(); i++) {
			capacity[in(i)][out(i)] = weight[i];
		}
#ifdef _DEBUG
		print2d();
#endif
		int max_flow = 0;
		while (true) {
			vector<int> parent(nv, -1);
			parent[0] = 0;
			queue<int> q;
			q.push(0);
			while (!q.empty() && parent[sink] == -1) {
				auto here = q.front(); q.pop();
				for (int there = 0; there < nv; there++) {
					if (capacity[here][there] - flow[here][there] > 0
					 && parent[there] == -1) {
						q.push(there);
						parent[there] = here;
					}
				}
			}
			if (parent[sink] == -1) break;
			int amount = inf;
			for (int p = sink; p != source; p = parent[p]) {
				amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
			}
			for (int p = sink; p != source; p = parent[p]) {
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}
			max_flow += amount;
		}
		cout << max_flow << endl;
	}
	return 0;
}
