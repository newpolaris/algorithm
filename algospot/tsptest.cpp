#include "DisjointSet.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double INF = 1e200;
const int MAX = 24, IN_MAX = 30;
int n;
double dist[30][30];
double best;
double minEdge[IN_MAX];

vector<int> nearest[MAX];
vector<pair<double, pair<int,int>>> edges;

double simpleHeuristic(vector<bool>& visited)
{
	double ret = minEdge[0];
	for (int i = 0; i < n; i++)
		if (!visited[i])
			ret += minEdge[i];
	return ret;
}

// here와 시작점, 아직 방문하지 않은 도시들을 모두 연결하는 MST를 찾는다.
double mstHeuristic(int here, const vector<bool>& visited) {
	// Knuskal's mst	
	DisjointSet set(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && visited[a]) continue;
		if (b != 0 && b != here && visited[b]) continue;
		if (set.merge(a, b))
			taken += edges[i].first;
	}
	return taken;
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
	int here = path.back();
	if (best <= currentLength + mstHeuristic(here, visited)) 
		return;

	if (pathReversePruning(path))
		return;

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
	edges.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			edges.push_back(make_pair(dist[i][j], make_pair(i,j)));
	sort(edges.begin(), edges.end());
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



