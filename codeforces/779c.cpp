#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <string.h>
#include <algorithm>

#define x first
#define y second

using namespace std;

using ll = long long;

int main() {
#ifdef _DEBUG
	freopen("779c0.in", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<int>> price(2, vector<int>(n));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &price[i][j]);
		}
	}
	vector<pair<int,int>> gap;
	vector<int> select(n, 1);
	for (int i = 0; i < n; i++) {
		gap.push_back({price[0][i] - price[1][i], i});
	}
	sort(gap.begin(), gap.end());
	for (int i = 0; i < n; i++) {
		if (gap[i].x > 0 && k <= i) 
			break;
		select[gap[i].y] = 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += price[select[i]][i];
	}
	printf("%d\n", sum);
	return 0;
}
