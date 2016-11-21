#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;
using pi = pair<int, int>;
int main() {
#ifdef _DEBUG
	freopen("timetrip.in", "r", stdin);
#endif
	int c, v, w, a, b, d;
	cin >> c;
	while (c--) {
		cin >> v >>  w;
		vector<vector<pi>> adj(v, vector<pi>());
		for (int l = 0; l < w; l++) {
			cin >> a >> b >> d;
			adj[a].emplace_back(b, d);
		}
		vector<vector<bool>> reachable(v, vector<bool>(v, false));
		for (int i = 0; i < v; i++) 
			reachable[i][i] = true;
		for (int a = 0; a < v; a++)
			for (auto& b : adj[a])
				reachable[a][b.first] = true;
		for (int a = 0; a < v; a++) 
			for (int i = 0; i < v; i++) 
				for (int j = 0; j < v; j++) 
					reachable[i][j] = reachable[i][j] or (reachable[i][a] and reachable[a][j]);
		int inf = 987654321;
		if (!reachable[0][1]) {
			cout << "UNREACHABLE" << endl;
			continue;
		}
		auto bellman2 = [&](int src, int target, function<int(int,int)> func) {
			vector<int> upper(v, inf);
			upper[src] = 0;
			for (int iter = 0; iter < v-1; iter++) 
				for (int here = 0; here < v; ++here)
					for (auto& k :adj[here]) {
						int there = k.first;
						int cost = k.second;
						upper[there] = min(upper[there], func(upper[here], cost));
					}
			for (int here = 0; here < v; ++here)
				for (auto& k : adj[here]) {
					int there = k.first;
					int cost = k.second;
					if (func(upper[here], cost) < upper[there])
						if (reachable[src][here] && reachable[here][target])
							return -inf;
				}
			return upper[target];
		};
		auto min =  bellman2(0, 1, plus<int>());
		auto max = -bellman2(0, 1, minus<int>());
		auto filter = [&](int i) { if (abs(i) > inf/2) return string("INFINITY"); else return to_string(i); };
		cout << filter(min) << " " << filter(max) << endl;
	}
	return 0;
}
