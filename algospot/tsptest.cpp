#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double INF = 1e200;
const int MAX = 20, IN_MAX = 30;
int n;
double dist[30][30];
double best;
double minEdge[IN_MAX];

vector<int> nearest[MAX];

double simpleHeuristic(vector<bool>& visited)
{
	double ret = minEdge[0];
	for (int i = 0; i < n; i++)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}

void search(vector<int>& path, vector<bool>& visited, double currentLength) {
	if (best <= currentLength + simpleHeuristic(visited)) return;
	int here = path.back();
	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
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
	vector<bool> visited(n, false);
	vector<int> path(1, 0);
	visited[0] = true;
	search(path, visited, 0);
	return best;
}

int main()
{
	freopen("tsptest.in", "r", stdin);
	cin >> n;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> dist[r][c];
		}
	}
	n = min(MAX, n);
	cout << solve() << endl;

	return 0;
}



