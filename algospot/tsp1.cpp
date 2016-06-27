#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const double INF = 1e200;
const int MAX = 20, IN_MAX = 20;
int n;
double dist[IN_MAX][IN_MAX];
double best;
double minEdge[IN_MAX];

vector<int> nearest[MAX];

double simpleHeuristic(vector<bool>& visited)
{
	double ret = 0;
	for (int i = 0; i < n; i++)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}

bool pathSwapPruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int p = path[path.size() - 4];
	int a = path[path.size() - 3];
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];

	return dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q];
}

bool pathReversePruning(const vector<int>& path) {
	if (path.size() < 4) return false;
	int b = path[path.size() - 2];
	int q = path[path.size() - 1];
	for (int i = 0; i + 3 < path.size(); ++i) {
		int p = path[i];
		int a = path[i + 1];
		if (dist[p][a] + dist[b][q] > dist[p][b] + dist[a][q])
			return true;
	}
	return false;
}

void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (best <= currentLength + simpleHeuristic(visited)) 
		return;
	if (pathReversePruning(path))
		return;
	int here = path.back();
	if (path.size() == n) {
		best = min(best, currentLength);
		return;
	}

	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;

		search(path, visited, currentLength + dist[here][next]);

		visited[next] = false;
		path.pop_back();
	}
}

double solve() {
	for (int i = 0; i< n; i++)
	{
		minEdge[i] = INF;
		for (int j = 0; j < n; ++j)
			if (i != j)
				minEdge[i] = min(minEdge[i], dist[i][j]);
	}
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> order;
		for (int j = 0; j < n; ++j)
			if (i != j)
				order.push_back(make_pair(dist[i][j], j));
		sort(order.begin(), order.end());
		nearest[i].clear();
		for (int j = 0; j < n-1; j++)
			nearest[i].push_back(order[j].second);
	}
	best = INF;
	for (int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		vector<int> path(1, i);
		visited[i] = true;
		search(path, visited, 0);
	}
	return best;
}

int main()
{
#ifdef _DEBUG
	freopen("tsp1.in", "r", stdin);
#endif
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				cin >> dist[r][c];
			}
		}
		n = min(MAX, n);
		cout << fixed << setprecision(10);
		cout << solve() << endl;
	}

	return 0;
}

