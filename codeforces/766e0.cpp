#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <numeric>

#define ALL(x) (x).begin(), (x).end()
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define x first
#define y second

using namespace std;

vector<vector<int>> adj;

// log2(pow(10,6)) = 19.93
const int MAX_BIT = 20;
const int MAX_NODE = 100005;
// Let arr[i][x] be the binary value of the xth bit of the number 
// attached to node i(just to make work easier).
int arr[MAX_NODE][MAX_BIT];

typedef long long ll;
ll res;
int n, a[100010];
vector<int> near[100010];
int dp[100010][21][2];
ll ans[MAX_BIT];

void dfs(int node, int p){
	for(int i = 0; i < 20; i++)
		dp[node][i][(a[node] & (1<<i)? 1: 0)] = 1;
		//initialize the dp vector as a bitset of a[i]
	for(auto next: near[node]){
		if(next-p <= 0) continue;
		dfs(next, node);
		for(int i = 0; i < 20; i++){ //break-down the problem and calculate it bit-by-bit
			auto next_ith_1 = dp[next][i][1];
			auto next_ith_0 = dp[next][i][0];
			auto node_ith_1 = dp[node][i][1];
			auto node_ith_0 = dp[node][i][0];
			auto num_path_ith_1 = next_ith_1 * node_ith_0 + next_ith_0 * node_ith_1;
			ans[i] += num_path_ith_1;

			if (a[node] & (1 << i))
				swap(dp[next][i][0], dp[next][i][1]);
			//Use swap for path xor 1
			dp[node][i][0] += dp[next][i][0], dp[node][i][1] += dp[next][i][1];
		}
	}
	return;
}

int main(){
#ifdef _DEBUG
	freopen("766e1.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n, p, q;
	cin >> n;
	REP(i, 0, n) {
		cin >> p;
		a[i] = p;
		REP(j, 0, MAX_BIT)
			arr[i][j] = (p & (1 << j));
	}
	res = accumulate(a+1, a+n+1, 0LL);
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		near[u].push_back(v);
		near[v].push_back(u);
	}
	dfs(1, 1);

	REP(i, 0, MAX_BIT)
		res += (ans[i]*(1 << i));
	cout << res << endl;
	return 0;
}
