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
// ans[i] which represents the number of paths that makes the ith bit sit to 1
typedef long long ll;
ll ans[MAX_BIT];
//  Let dp[i][x][j] be the number of paths going down from node i 
// that makes the xth bit's value equal to j
ll dp[MAX_NODE][MAX_BIT][2];

void dfs(int node, int pnode){
	REP(i, 0, MAX_BIT) {
		// 기본 상태로 a[node]의 i-th bit가 0, 1 인지 추가
		int a_ith_bit = arr[node][i];
		dp[node][i][a_ith_bit] = 1;
	}
	for (auto next: adj[node]) {
		// pnode와 같은지만 테스트. index 크고 작음과 순서는 상관 없음
		if (next - pnode == 0) continue;
		dfs(next, node);
		REP(i, 0, MAX_BIT) {
			// Foreach of the child of dp[node] use dp to get amount of paths 
			// that will have the i-th bit 1(flagged)
			auto next_ith_1 = dp[next][i][1];
			auto next_ith_0 = dp[next][i][0];
			auto node_ith_1 = dp[node][i][1];
			auto node_ith_0 = dp[node][i][0];
			auto num_path_ith_1 = next_ith_1 * node_ith_0 + next_ith_0 * node_ith_1;
			ans[i] += num_path_ith_1;

			/* 
			 * merge the child subtree into dp[now]
			 * so in the operation res += XX, 
			 * every path from the explored subtree will be matched with 
			 * the subtree that is being explored
			 *
			 * node:next 일 때 0:0 은 0, 0:1은 1이나, 1:0은 1, 1:1은 0이라서 뒤집는게 필요
			 */
			if (arr[node][i])
				swap(next_ith_0, next_ith_1);
			dp[node][i][0] += next_ith_0, dp[node][i][1] += next_ith_1;
		}
	}
	REP(i, 0, MAX_BIT)
		ans[i] += arr[node][i];
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
		REP(j, 0, MAX_BIT)
			// bit 를 세기 위해 대소 비교
			arr[i][j] = (p & (1 << j)) > 0;
	}
	adj.resize(n);
	REP(i, 1, n) {
		cin >> p >> q;
		p--, q--;
		// 큰 것을 기준으로 한 가지만 남긴다
		adj[p].push_back(q);
		adj[q].push_back(p);
	}
	dfs(0, -1);
	ll res = 0;
	REP(i, 0, MAX_BIT)
		res += (ans[i]*(1 << i));
	cout << res << endl;
	return 0;
}
