#include <iostream>
#include <functional>
#include <vector>
#include <iomanip>
#include <queue>
#include <limits>

using namespace std;

const int MaxN = 10000;
const auto INF = numeric_limits<double>::infinity();
typedef pair<double, int> Node;

int main()
{
#ifdef _DEBUG
	freopen("routing.in", "r", stdin);
#endif
	int a, b, c, n, m;
	double noise;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		vector<Node> adj[MaxN];

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> noise;
			adj[a].push_back({noise, b});
			adj[b].push_back({noise, a});
		}

		vector<double> v(n, INF);
		priority_queue<Node> Q;

		Q.push({-1.0, 0});
		v[0] = 1.0;

		while (!Q.empty()) {
			int minI = Q.top().second;
			auto cost = -Q.top().first;
			Q.pop();

			if (v[minI] < cost)
				continue;

			for (auto &e : adj[minI]) {
				auto noise = cost * e.first;
				int k = e.second;
				if (v[k] > noise) {
					v[k] = noise;
					Q.push({-noise, k});
				}
			}
		}

		cout << fixed << setprecision(10) << v[n-1] << endl;
	}
	return 0;
}
