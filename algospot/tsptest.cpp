#include "DisjointSet.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

const double INF = 1e200;
const int MAX = 20, IN_MAX = 30;
const int CACHED_DEPTH = 5;
int n;
double dist[30][30];
double best;
double minEdge[IN_MAX];

vector<int> nearest[MAX];
vector<pair<double, pair<int,int>>> edges;
map<int, double> cache[MAX][CACHED_DEPTH+1];

double simpleHeuristic(int visited)
{
	double ret = minEdge[0];
	for (int i = 0; i < n; i++)
		if (visited & (1<<i))
			ret += minEdge[i];
	return ret;
}

// here와 시작점, 아직 방문하지 않은 도시들을 모두 연결하는 MST를 찾는다.
double mstHeuristic(int here, int visited) {
	// Knuskal's mst	
	DisjointSet set(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); i++)
	{
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != 0 && a != here && (visited & 1 << a)) continue;
		if (b != 0 && b != here && (visited & 1 << b)) continue;
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

double dp(int here, int visited) 
{
	if (visited == (1<<n) - 1) return dist[here][0];
	int remaining = n - __builtin_popcount(visited);
	double& ret = cache[here][remaining][visited];
	if (ret > 0) return ret;
	ret = INF;
	for (int next = 0; next < n; ++next)
	{
		if (visited & (1 << next)) continue;
		ret = min(ret, dp(next, visited + (1<<next)) + dist[here][next]);
	}
	return ret;
}

void search(vector<int>& path, int visited, double currentLength) {
	int here = path.back();
	if (best <= currentLength + mstHeuristic(here, visited)) 
		return;

	if (pathReversePruning(path))
		return;

	if (path.size() + CACHED_DEPTH >= n) {
		best = min(best, currentLength + dp(here, visited));
		return;
	}

	if (path.size() == n) {
		best = min(best, currentLength + dist[here][0]);
		return;
	}

	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
		if (visited & (1 << next)) continue;
		path.push_back(next);
		search(path, visited + (1 << next), currentLength + dist[here][next]);
		path.pop_back();
	}
}

// here현재 위치
// visited 각 도시의 방문 여부 일때, 나머지 도시를 모두 방문하고
// 시작점으로 돌아가는 최단 경로의 길이를 반환한다.
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
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j <= CACHED_DEPTH; ++j)
			cache[i][j].clear();

	edges.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			edges.push_back(make_pair(dist[i][j], make_pair(i,j)));
	sort(edges.begin(), edges.end());
	best = INF;
	vector<int> path(1, 0);
	search(path, 1, 0);
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



