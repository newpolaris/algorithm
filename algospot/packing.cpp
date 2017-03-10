#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int dp[101][1001];

int main() {
#ifdef _DEBUG
	freopen("packing.in", "r", stdin);
#endif
	int t, c, v, n, w;
	cin >> c;

	while (c--) {
		memset(dp, 0, sizeof(dp));
		cin >> n >> w;
		vector<string> name(n);
		vector<int> vol(n), need(n);
		for (int i = 0; i < n; i++)
			cin >> name[i] >> vol[i] >> need[i];
		// 상품 하나에 대해 모든 돈의 경우를 채우는 방식
		for (int k = 1; k <= n; k++) {
			for (int i = 0; i <= w; i++) {
				int& r = dp[k][i];
				// 사용 안했을 경우의 최대값 유지
				r = dp[k-1][i];
				if (i - vol[k-1] < 0) continue;
				// 사용 했을 때 만족도 갱신
				r = max(r, dp[k-1][i - vol[k-1]] + need[k-1]);
			}
		}
		int remainW = w;
		vector<int> sol;
		for (int i = n-1; i >= 0; --i) {
			if (dp[i+1][remainW] == dp[i][remainW]) 
				continue;
			sol.push_back(i);
			remainW -= vol[i];
		}
		cout << dp[n][w] << " " << sol.size() << endl;
		for (auto i : sol)
			cout << name[i] << endl;
	}

	return 0;
}
