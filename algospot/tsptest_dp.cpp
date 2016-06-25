#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double INF = 1e200;
const int MAX = 12;
int n;
double dist[MAX][MAX];
double cache[MAX][1<<MAX];

double shortestPath(int here, int visited)
{
	if (visited == (1<<n)-1) 
		return dist[here][0];
	double& ret = cache[here][visited];
	if (ret >= 0) return ret;
	ret = INF;
	for (int next = 0; next < n; ++next) {
		if (visited & (1<<next)) continue;
		double cand = dist[here][next] +
			shortestPath(next, visited + (1<<next));
		ret = min(ret, cand);
	}
	return ret;
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
	memset(cache, -1, sizeof(cache));
	cout << shortestPath(0, 1 << 0) << endl;

	return 0;
}


