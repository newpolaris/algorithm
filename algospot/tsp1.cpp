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
// 모든 도시 간의 도로를 길이 순으로 정렬해 저장해 둔다.
vector<pair<double,pair<int,int>>> edges;

// 상호 배타적 집합 자료 구조를 구현한다.
struct DisjointSet {
	// n개의 원소로 구성된 집합 자료 구조를 만든다.
	DisjointSet(int n);
	// here가 포함된 집합의 대표를 반환한다.
	int find(int here);
	// a가 포함된 집합과 b가 포함된 집합을 합친다.
	bool merge(int a, int b);

	vector<int> P, Rank;
};

DisjointSet::DisjointSet(int n)
{
	P.resize(n);
	for (int i = 0; i < n; i++)
		P[i] = i;
	Rank = vector<int>(n, 0);
}

int DisjointSet::find(int here)
{
	if (P[here] != here)
		P[here] = find(P[here]);
	return P[here];
}

bool DisjointSet::merge(int a, int b)
{
	int ra = find(a), rb = find(b);
	if (ra == rb) return false;
	if (Rank[ra] > Rank[rb])
		P[rb] = ra;
	else
		P[ra] = rb;
	if (Rank[ra] == Rank[rb]) 
		Rank[rb] = Rank[ra] + 1;
	return true;
}


// here와 시작점, 아직 방문하지 않은 도시들을 모두 연결하는 MST를 찾는다.
double mstHeuristic(int here, const vector<bool>& visited) {
	// Knuskal's mst	
	DisjointSet sets(n);
	double taken = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != here && visited[a]) continue;
		if (b != here && visited[b]) continue;
		if (sets.merge(a, b))
			taken += edges[i].first;
	}
	return taken;
}

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

void search(vector<int>& path, vector<bool>& visited, double currLen) {
	if (pathReversePruning(path))
		return;
	int here = path.back();
	if (best <= currLen + mstHeuristic(here, visited)) 
		return;
	if (path.size() == n) {
		best = min(best, currLen);
		return;
	}

	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
		if (visited[next]) continue;
		path.push_back(next);
		visited[next] = true;

		search(path, visited, currLen + dist[here][next]);

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
		for (int j = 0; j < i; ++j)
			edges.push_back(make_pair(dist[i][j], make_pair(i, j)));
	sort(edges.begin(), edges.end());

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

