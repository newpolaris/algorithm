#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
const int max_v = 2000, inf = 1000000;
int n;
vector<int> weight;
vector<pair<int, int>> adj[max_v];
bool hasPath(int lo, int hi) {
	int s = 0;
	lo = weight[lo], hi = weight[hi];
	vector<bool> visited(n, false);
	stack<int> stack;
	stack.push(s);
	while (!stack.empty()) {
		s = stack.top();
		stack.pop();
		if (!visited[s]) 
			visited[s] = true;
		if (s == n-1)
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
// @Method0 : 2283 ms
int binarySearchMinUpperBound() {
	int ret = inf;
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++) {
		auto upper = binarySearchMinUpperBound(i);
		if (upper > inf/2) break;
		ret = min(ret, upper - weight[i]);
	}
	return ret;
}

struct DisjointSet {
	vector<int> rank, parent; 
	DisjointSet(int len) {
		rank = vector<int>(len, 0);
		parent.resize(len);
		for (int i = 0; i < len; i++)
			parent[i] = i;
	}
	int find(int here) {
		if (here != parent[here])
			parent[here] = find(parent[here]);
		return parent[here];
	}
	bool merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (rank[a] > rank[b]) 
			swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) 
			++rank[b];
		return true;
	}
};
int kruskalMinUpperBound(vector<pair<int, pair<int, int>>>& edges, int low) {
	DisjointSet sets(n);
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].first < weight[low]) continue;
		sets.merge(edges[i].second.first, edges[i].second.second);
		if (sets.find(0) == sets.find(n-1))
			return edges[i].first;
	}
	return inf;
}
// @Method1 : 404 ms
int kruskalMinUpperBound() {
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < n; i++) {
		for (auto & p : adj[i]) {
			if (i >= p.first) continue;
			edges.push_back({p.second, {i, p.first}});
		}
	}
	sort(edges.begin(), edges.end());
	int ret = inf;
	sort(weight.begin(), weight.end());
	for (int i = 0; i < weight.size(); i++) {
		auto upper = kruskalMinUpperBound(edges, i);
		if (upper > inf/2) break;
		ret = min(ret, upper - weight[i]);
	}
	return ret;
}

// @Method2 : 712 ms
int brute() {
	sort(weight.begin(), weight.end());
	int ret = inf, foundPathUsing = 0;
	for (int lo = 0; lo < weight.size(); ++lo) {
		bool foundPath = false;
		for (int hi = foundPathUsing; hi < weight.size(); ++hi) {
			if (hasPath(lo, hi)) {
				ret = min(ret, weight[hi] - weight[lo]);
				foundPath = true;
				foundPathUsing = hi;
				break;
			}
		}
		if (!foundPath)
			break;
	}
	return ret;
}

// @Method3 : 708 ms
int scanning() {
	sort(weight.begin(), weight.end());
	int lo = 0, hi = 0, ret = inf;
	while (true) {
		if (hasPath(lo, hi)) {
			ret = min(ret, weight[hi] - weight[lo]);
			++lo;
		} else {
			if (hi == weight.size() - 1)
				break;
			++hi;
		}
	}
	return ret;
}

int main() {
#ifdef _DEBUG
	freopen("tpath.in", "r", stdin);
#endif
	int c, m, a, b, v;
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
		cout << 
		// binarySearchMinUpperBound() 
		// kruskalMinUpperBound()
		// brute()
		scanning()
		<< endl;
		
	}
	return 0;
}
