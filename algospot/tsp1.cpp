#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

const double INF = 1e200;
const int MAX = 20, IN_MAX = 20;
int n;
double dist[IN_MAX][IN_MAX];
double best;
double minEdge[IN_MAX];
const int CACHED_DEPTH = 5;

vector<int> nearest[MAX];
// 모든 도시 간의 도로를 길이 순으로 정렬해 저장해 둔다.
vector<pair<double,pair<int,int>>> edges;
map<int, double> cache[MAX][CACHED_DEPTH+1];

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
double mstHeuristic(int here, int visited) {
	// Knuskal's mst	
	DisjointSet sets(n);
	double taken = 0;
	// sort 된 edges
	for (int i = 0; i < edges.size(); ++i) {
		int a = edges[i].second.first, b = edges[i].second.second;
		if (a != here && (visited & 1<<a)) continue;
		if (b != here && (visited & 1<<b)) continue;
		if (sets.merge(a, b))
			taken += edges[i].first;
	}
	return taken;
}

double simpleHeuristic(int visited)
{
	double ret = 0;
	for (int i = 0; i < n; i++)
		if (!(visited & (1<<i)))
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

double dp(int here, int visited) 
{
	if (visited == (1<<n) - 1) return 0;
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

void search(vector<int>& path, int visited, double currLen) {
	if (pathReversePruning(path))
		return;
	int here = path.back();
	if (best <= currLen + mstHeuristic(here, visited)) 
		return;
	if (path.size() + CACHED_DEPTH >= n) {
		best = min(best, currLen + dp(here, visited));
		return;
	}
	if (path.size() == n) {
		best = min(best, currLen);
		return;
	}

	for (int i = 0; i < nearest[here].size(); ++i) {
		int next = nearest[here][i];
		if (visited & (1<<next)) continue;
		path.push_back(next);
		search(path, visited + (1<<next), currLen + dist[here][next]);
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

	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j <= CACHED_DEPTH; ++j)
			cache[i][j].clear();

	best = INF;
	for (int i = 0; i < n; i++) {
		vector<int> path(1, i);
		search(path, 1<<i, 0);
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

