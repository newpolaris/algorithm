#include <iostream>
#include <map>
#include <string.h>
#include <vector>

using namespace std;

const int MAX_N = 16;
int N, col[MAX_N], ld[MAX_N*2], rd[MAX_N*2];

int dfs(int c) {
	if (c >= N) return 1;
	int sum = 0;
	for (int r = 0; r < N; r++) {
		if (col[r] || ld[c+r] || rd[N-r+c]) continue;
		col[r] = ld[c+r] = rd[N-r+c] = 1;
		sum += dfs(c+1);
		col[r] = ld[c+r] = rd[N-r+c] = 0;
	}
	return sum;
}

int main() {
#ifdef _DEBUG
	freopen("9663.in", "r", stdin);
#endif
	cin >> N;
	memset(col, 0, sizeof(col));
	memset(ld, 0, sizeof(ld));
	memset(rd, 0, sizeof(rd));
	cout << dfs(0) << endl;
	return 0;
}
