#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 500;
int delay[MAX_V];
int adj[MAX_V][MAX_V], W[MAX_V][MAX_V];

int main() {
#ifdef _DEBUG
	freopen("drunken.in", "r", stdin);
#endif
	int v, e, a, b, c, t;
	cin >> v >> e;
	for (int i = 0; i < v; i++)
		 cin >> delay[i];
	vector<pair<int, int>> order;
	for (int i = 0; i < v; i++)
		order.push_back(make_pair(delay[i], i));
	sort(order.begin(), order.end());
	for (int i = 0; i < v; i++) 
		for (int j = 0; j < v; j++) 
			adj[i][j] = 987654321;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[b-1][a-1] = adj[a-1][b-1] = c;
	}
	for (int i = 0; i < v; i++) 
		for (int j = 0; j < v; j++) 
			W[i][j] = (i == j ? 0 : adj[i][j]);
	for (int i = 0; i < v; i++) {
		auto w = order[i].second;
		auto d = order[i].first;
		for (int i = 0; i < v; i++) 
			for (int j = 0; j < v; j++) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				W[i][j] = min(W[i][j], adj[i][w] + adj[w][j] + d);
			}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << W[a-1][b-1] << endl;

	}
	return 0;
}
