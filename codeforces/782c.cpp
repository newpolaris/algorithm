#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <functional>
#include <string.h>

#define x first
#define y second
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

vector<vector<int>> adj;
int color[200001];
int visit[200001];

int dfs(int cur, int par) {
	if (visit[cur]) return 0;
	visit[cur] = 1;
	int ci = 1;
	if (par == -1) par = cur;
	function<int()> nextcolor = [&]() -> int {
		if (ci == color[cur] || ci == color[par]) 
			ci++;
		if (ci == color[cur] || ci == color[par]) 
			ci++;
		return ci++;
	};
	for (auto& a : adj[cur]) {
		if (color[a] == -1) {
			color[a] = nextcolor();
		}
		dfs(a, cur);
	}
	return 0;
}

int main() {
#ifdef _DEBUG
	freopen("782c1.in", "r", stdin);
#endif
	int n, a, b;
	scanf("%d", &n);
	memset(color, -1, sizeof(color)); 
	memset(visit, 0, sizeof(visit)); 
	adj.assign(n, vector<int>());
	forn(i, 1, n) {
		scanf("%d%d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	color[0] = 1;
	dfs(0, -1);
	int cnt = 0;
	forn (i, 0, n)
		cnt = max(cnt, color[i]);
	printf("%d\n", cnt);
	forn (i, 0, n)
		printf("%d%c", color[i], " \n"[i+1 == n]);
	return 0;
}
