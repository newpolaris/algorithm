#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
const int max_v = 2000, inf = 1000000;
vector<int> weight;
vector<pair<int, int>> adj[max_v];
bool hasPath(int lo, int hi) {
	int s = 0, v = weight.size();
	lo = weight[lo], hi = weight[hi];
	vector<bool> visited(v, false);
	stack<int> stack;
	stack.push(s);
	while (!stack.empty()) {
		s = stack.top();
		stack.pop();
		if (!visited[s]) 
			visited[s] = true;
		if (s == v-1)
			return true;
		for (auto& a : adj[s]) {
			if (!visited[a.first] && lo <= a.second && a.second <= hi)
				stack.push(a.first);
		}
	}
	return false;
}
int binarySearchMinUpperBound(int low) {
	int lo = low, hi = weight.size();
	while (lo < hi) {
		int mid = lo + (hi-lo)/2;
		if (hasPath(low, mid))
			hi = mid;
		else
			lo = mid+1;
	}
	if (!hasPath(low, lo)) 
		return inf;
	return weight[lo];
}
// @Method0
int binarySearchMinUpperBound() {
	int ret = inf;
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++) {
		ret = min(ret, binarySearchMinUpperBound(i) - weight[i]);
	}
	return ret;
}
int main() {
#ifdef _DEBUG
	freopen("tpath.in", "r", stdin);
#endif
	int c, n, m, a, b, v;
	cin >> c;
	while (c--) {
		cin >> n >> m;
		weight.resize(m);
		for (auto& a : adj) a.clear();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> v;
			weight[i] = v;
			adj[a].push_back({b, v});
			adj[b].push_back({a, v});
		}
		cout << binarySearchMinUpperBound() << endl;
	}
	return 0;
}
