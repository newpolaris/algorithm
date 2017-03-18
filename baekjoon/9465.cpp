#include <cstdio>
#include <vector>

int sc[100000][2], c[100000][2];
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
#ifdef _DEBUG
	freopen("9465.in", "r", stdin);
#endif
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < n; i++)
				scanf("%d", &sc[i][j]);
		c[0][0] = sc[0][0];
		c[0][1] = sc[0][1];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				c[i][j] = max(sc[i][j]+c[i-1][(j+1)%2], c[i-1][j]);
			}
		}
		printf("%d\n", max(c[n-1][0], c[n-1][1]));
	}
	return 0;
}
