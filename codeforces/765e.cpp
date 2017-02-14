#include <iostream>
#include <string>
#include <string.h>
#include <iostream>
#include <regex>
#include <cassert>
#include <map>
#include <set>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define forn(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

vector<vector<int>> adj;
int main() {
#ifdef _DEBUG
	freopen("765c1.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	int n, a, b;
	cin >> n;

	adj.resize(n-1);
	forn(i, 0, n-1) {
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	return 0;
}
